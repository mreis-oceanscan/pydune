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

void pbPlanControlState(py::module &m) {
	auto vPlanControlState = py::class_<PlanControlState, Message>(m, "PlanControlState", "Plan Control State");
	vPlanControlState.def(py::init<>());
	vPlanControlState.def("__setstate__", &pbUnpickleMessage<PlanControlState>);
	
	vPlanControlState.def_property("state",
	    [](const PlanControlState &x){return static_cast<PlanControlState::StateEnum>(x.state);},
	    [](PlanControlState *x, const uint8_t &y){x->state = y;},
	    "");
	
	vPlanControlState.def_property("plan_id",
	    [](const PlanControlState &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanControlState &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	vPlanControlState.def_readwrite("plan_eta", &PlanControlState::plan_eta);
	vPlanControlState.def_readwrite("plan_progress", &PlanControlState::plan_progress);
	
	vPlanControlState.def_property("man_id",
	    [](const PlanControlState &x){return ascii_to_unicode_safe(x.man_id);},
	    [](PlanControlState &x, std::string &s){x.man_id = s;}, py::return_value_policy::take_ownership);
	vPlanControlState.def_readwrite("man_type", &PlanControlState::man_type);
	vPlanControlState.def_readwrite("man_eta", &PlanControlState::man_eta);
	
	vPlanControlState.def_property("last_outcome",
	    [](const PlanControlState &x){return static_cast<PlanControlState::LastPlanOutcomeEnum>(x.last_outcome);},
	    [](PlanControlState *x, const uint8_t &y){x->last_outcome = y;},
	    "");

	py::enum_<PlanControlState::StateEnum>(vPlanControlState, "StateEnum", "State")
		.value("BLOCKED", PlanControlState::StateEnum::PCS_BLOCKED)
		.value("READY", PlanControlState::StateEnum::PCS_READY)
		.value("INITIALIZING", PlanControlState::StateEnum::PCS_INITIALIZING)
		.value("EXECUTING", PlanControlState::StateEnum::PCS_EXECUTING);

	py::enum_<PlanControlState::LastPlanOutcomeEnum>(vPlanControlState, "LastPlanOutcomeEnum", "Last Plan Outcome")
		.value("NONE", PlanControlState::LastPlanOutcomeEnum::LPO_NONE)
		.value("SUCCESS", PlanControlState::LastPlanOutcomeEnum::LPO_SUCCESS)
		.value("FAILURE", PlanControlState::LastPlanOutcomeEnum::LPO_FAILURE);
}