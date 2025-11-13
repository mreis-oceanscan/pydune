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

void pbPlanControl(py::module &m) {
	auto vPlanControl = py::class_<PlanControl, Message>(m, "PlanControl", "Plan Control");
	vPlanControl.def(py::init<>());
	vPlanControl.def("__setstate__", &pbUnpickleMessage<PlanControl>);
	
	vPlanControl.def_property("type",
	    [](const PlanControl &x){return static_cast<PlanControl::TypeEnum>(x.type);},
	    [](PlanControl *x, const uint8_t &y){x->type = y;},
	    "");
	
	vPlanControl.def_property("op",
	    [](const PlanControl &x){return static_cast<PlanControl::OperationEnum>(x.op);},
	    [](PlanControl *x, const uint8_t &y){x->op = y;},
	    "");
	vPlanControl.def_readwrite("request_id", &PlanControl::request_id);
	
	vPlanControl.def_property("plan_id",
	    [](const PlanControl &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanControl &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	vPlanControl.def_readwrite("flags", &PlanControl::flags);
	
	vPlanControl.def_property("arg",
	[](const PlanControl &x){return x.arg.isNull() ? nullptr : x.arg.get();},
	[](PlanControl *x, const py::handle &y){
	    if(y.is_none()){
	        x->arg.clear();
	    } else {
	        try {
	            x->arg.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->arg.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vPlanControl.def_property("info",
	    [](const PlanControl &x){return ascii_to_unicode_safe(x.info);},
	    [](PlanControl &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<PlanControl::TypeEnum>(vPlanControl, "TypeEnum", "Type")
		.value("REQUEST", PlanControl::TypeEnum::PC_REQUEST)
		.value("SUCCESS", PlanControl::TypeEnum::PC_SUCCESS)
		.value("FAILURE", PlanControl::TypeEnum::PC_FAILURE)
		.value("IN_PROGRESS", PlanControl::TypeEnum::PC_IN_PROGRESS);

	py::enum_<PlanControl::OperationEnum>(vPlanControl, "OperationEnum", "Operation")
		.value("START", PlanControl::OperationEnum::PC_START)
		.value("STOP", PlanControl::OperationEnum::PC_STOP)
		.value("LOAD", PlanControl::OperationEnum::PC_LOAD)
		.value("GET", PlanControl::OperationEnum::PC_GET);

	py::enum_<PlanControl::FlagsBits>(vPlanControl, "FlagsBits", "Flags", py::arithmetic())
		.value("CALIBRATE", PlanControl::FlagsBits::FLG_CALIBRATE)
		.value("IGNORE_ERRORS", PlanControl::FlagsBits::FLG_IGNORE_ERRORS);
}