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

void pbEntityActivationState(py::module &m) {
	auto vEntityActivationState = py::class_<EntityActivationState, Message>(m, "EntityActivationState", "Entity Activation State");
	vEntityActivationState.def(py::init<>());
	vEntityActivationState.def("__setstate__", &pbUnpickleMessage<EntityActivationState>);
	
	vEntityActivationState.def_property("state",
	    [](const EntityActivationState &x){return static_cast<EntityActivationState::StateEnum>(x.state);},
	    [](EntityActivationState *x, const uint8_t &y){x->state = y;},
	    "");
	
	vEntityActivationState.def_property("error",
	    [](const EntityActivationState &x){return ascii_to_unicode_safe(x.error);},
	    [](EntityActivationState &x, std::string &s){x.error = s;}, py::return_value_policy::take_ownership);

	py::enum_<EntityActivationState::StateEnum>(vEntityActivationState, "StateEnum", "State")
		.value("INACTIVE", EntityActivationState::StateEnum::EAS_INACTIVE)
		.value("ACTIVE", EntityActivationState::StateEnum::EAS_ACTIVE)
		.value("ACT_IP", EntityActivationState::StateEnum::EAS_ACT_IP)
		.value("ACT_DONE", EntityActivationState::StateEnum::EAS_ACT_DONE)
		.value("ACT_FAIL", EntityActivationState::StateEnum::EAS_ACT_FAIL)
		.value("DEACT_IP", EntityActivationState::StateEnum::EAS_DEACT_IP)
		.value("DEACT_DONE", EntityActivationState::StateEnum::EAS_DEACT_DONE)
		.value("DEACT_FAIL", EntityActivationState::StateEnum::EAS_DEACT_FAIL);
}