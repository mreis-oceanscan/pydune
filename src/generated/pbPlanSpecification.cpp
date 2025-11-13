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

void pbPlanSpecification(py::module &m) {
	auto vPlanSpecification = py::class_<PlanSpecification, Message>(m, "PlanSpecification", "Plan Specification");
	vPlanSpecification.def(py::init<>());
	vPlanSpecification.def("__setstate__", &pbUnpickleMessage<PlanSpecification>);
	
	vPlanSpecification.def_property("plan_id",
	    [](const PlanSpecification &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanSpecification &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	
	vPlanSpecification.def_property("description",
	    [](const PlanSpecification &x){return ascii_to_unicode_safe(x.description);},
	    [](PlanSpecification &x, std::string &s){x.description = s;}, py::return_value_policy::take_ownership);
	
	vPlanSpecification.def_property("vnamespace",
	    [](const PlanSpecification &x){return ascii_to_unicode_safe(x.vnamespace);},
	    [](PlanSpecification &x, std::string &s){x.vnamespace = s;}, py::return_value_policy::take_ownership);
	vPlanSpecification.def_readwrite("variables", &PlanSpecification::variables);
	
	vPlanSpecification.def_property("start_man_id",
	    [](const PlanSpecification &x){return ascii_to_unicode_safe(x.start_man_id);},
	    [](PlanSpecification &x, std::string &s){x.start_man_id = s;}, py::return_value_policy::take_ownership);
	vPlanSpecification.def_readwrite("maneuvers", &PlanSpecification::maneuvers);
	vPlanSpecification.def_readwrite("transitions", &PlanSpecification::transitions);
	vPlanSpecification.def_readwrite("start_actions", &PlanSpecification::start_actions);
	vPlanSpecification.def_readwrite("end_actions", &PlanSpecification::end_actions);
}