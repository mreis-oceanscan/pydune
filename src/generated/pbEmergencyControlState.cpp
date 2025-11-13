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

void pbEmergencyControlState(py::module &m) {
	auto vEmergencyControlState = py::class_<EmergencyControlState, Message>(m, "EmergencyControlState", "Emergency Control State");
	vEmergencyControlState.def(py::init<>());
	vEmergencyControlState.def("__setstate__", &pbUnpickleMessage<EmergencyControlState>);
	
	vEmergencyControlState.def_property("state",
	    [](const EmergencyControlState &x){return static_cast<EmergencyControlState::StateEnum>(x.state);},
	    [](EmergencyControlState *x, const uint8_t &y){x->state = y;},
	    "");
	
	vEmergencyControlState.def_property("plan_id",
	    [](const EmergencyControlState &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](EmergencyControlState &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	vEmergencyControlState.def_readwrite("comm_level", &EmergencyControlState::comm_level);

	py::enum_<EmergencyControlState::StateEnum>(vEmergencyControlState, "StateEnum", "State")
		.value("NOT_CONFIGURED", EmergencyControlState::StateEnum::ECS_NOT_CONFIGURED)
		.value("DISABLED", EmergencyControlState::StateEnum::ECS_DISABLED)
		.value("ENABLED", EmergencyControlState::StateEnum::ECS_ENABLED)
		.value("ARMED", EmergencyControlState::StateEnum::ECS_ARMED)
		.value("ACTIVE", EmergencyControlState::StateEnum::ECS_ACTIVE)
		.value("STOPPING", EmergencyControlState::StateEnum::ECS_STOPPING);
}