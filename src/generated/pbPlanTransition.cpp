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

void pbPlanTransition(py::module &m) {
	auto vPlanTransition = py::class_<PlanTransition, Message>(m, "PlanTransition", "Plan Transition");
	vPlanTransition.def(py::init<>());
	vPlanTransition.def("__setstate__", &pbUnpickleMessage<PlanTransition>);
	
	vPlanTransition.def_property("source_man",
	    [](const PlanTransition &x){return ascii_to_unicode_safe(x.source_man);},
	    [](PlanTransition &x, std::string &s){x.source_man = s;}, py::return_value_policy::take_ownership);
	
	vPlanTransition.def_property("dest_man",
	    [](const PlanTransition &x){return ascii_to_unicode_safe(x.dest_man);},
	    [](PlanTransition &x, std::string &s){x.dest_man = s;}, py::return_value_policy::take_ownership);
	
	vPlanTransition.def_property("conditions",
	    [](const PlanTransition &x){return ascii_to_unicode_safe(x.conditions);},
	    [](PlanTransition &x, std::string &s){x.conditions = s;}, py::return_value_policy::take_ownership);
	vPlanTransition.def_readwrite("actions", &PlanTransition::actions);
}