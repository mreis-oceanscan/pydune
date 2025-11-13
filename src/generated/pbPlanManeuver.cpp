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

void pbPlanManeuver(py::module &m) {
	auto vPlanManeuver = py::class_<PlanManeuver, Message>(m, "PlanManeuver", "Plan Maneuver");
	vPlanManeuver.def(py::init<>());
	vPlanManeuver.def("__setstate__", &pbUnpickleMessage<PlanManeuver>);
	
	vPlanManeuver.def_property("maneuver_id",
	    [](const PlanManeuver &x){return ascii_to_unicode_safe(x.maneuver_id);},
	    [](PlanManeuver &x, std::string &s){x.maneuver_id = s;}, py::return_value_policy::take_ownership);
	
	vPlanManeuver.def_property("data",
	[](const PlanManeuver &x){return x.data.isNull() ? nullptr : x.data.get();},
	[](PlanManeuver *x, const py::handle &y){
	    if(y.is_none()){
	        x->data.clear();
	    } else {
	        try {
	            x->data.set(y.cast<Maneuver*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Maneuver or NoneType.");
	        }
	        x->data.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	vPlanManeuver.def_readwrite("start_actions", &PlanManeuver::start_actions);
	vPlanManeuver.def_readwrite("end_actions", &PlanManeuver::end_actions);
}