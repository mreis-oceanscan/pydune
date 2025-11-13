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

void pbArmingState(py::module &m) {
	auto vArmingState = py::class_<ArmingState, Message>(m, "ArmingState", "Arming State");
	vArmingState.def(py::init<>());
	vArmingState.def("__setstate__", &pbUnpickleMessage<ArmingState>);
	
	vArmingState.def_property("state",
	    [](const ArmingState &x){return static_cast<ArmingState::StateEnum>(x.state);},
	    [](ArmingState *x, const uint8_t &y){x->state = y;},
	    "");

	py::enum_<ArmingState::StateEnum>(vArmingState, "StateEnum", "State")
		.value("ARMED", ArmingState::StateEnum::MOTORS_ARMED)
		.value("DISARMED", ArmingState::StateEnum::MOTORS_DISARMED);
}