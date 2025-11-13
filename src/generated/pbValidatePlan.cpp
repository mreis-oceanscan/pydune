#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <DUNE/IMC/Message.hpp>
#include <DUNE/IMC/SuperTypes.hpp>
#include <DUNE/IMC/Definitions.hpp>
#include <DUNE/IMC/Enumerations.hpp>
#include "../pbUtils.hpp"
#include "../pbPacket.hpp"
namespace py = pybind11;
using namespace DUNE::IMC;

void pbValidatePlan(py::module &m) {
	auto vValidatePlan = py::class_<ValidatePlan, Message>(m, "ValidatePlan", "Validate Plan DB");
	vValidatePlan.def(py::init<>());
	vValidatePlan.def("__setstate__", &pbUnpickleMessage<ValidatePlan>);
	
	vValidatePlan.def_property("type",
	    [](const ValidatePlan &x){return static_cast<ValidatePlan::RequestTypeEnum>(x.type);},
	    [](ValidatePlan *x, const uint8_t &y){x->type = y;},
	    "");
	
	vValidatePlan.def_property("plan",
	[](const ValidatePlan &x){return x.plan.isNull() ? nullptr : x.plan.get();},
	[](ValidatePlan *x, const py::handle &y){
	    if(y.is_none()){
	        x->plan.clear();
	    } else {
	        try {
	            x->plan.set(y.cast<PlanDB*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are PlanDB or NoneType.");
	        }
	        x->plan.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<ValidatePlan::RequestTypeEnum>(vValidatePlan, "RequestTypeEnum", "Request Type")
		.value("REQ", ValidatePlan::RequestTypeEnum::VPS_REQ)
		.value("VALID", ValidatePlan::RequestTypeEnum::VPS_VALID)
		.value("INVALID", ValidatePlan::RequestTypeEnum::VPS_INVALID);
}