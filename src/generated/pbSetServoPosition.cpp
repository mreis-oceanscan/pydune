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

void pbSetServoPosition(py::module &m) {
	auto vSetServoPosition = py::class_<SetServoPosition, Message>(m, "SetServoPosition", "Set Servo Position");
	vSetServoPosition.def(py::init<>());
	vSetServoPosition.def("__setstate__", &pbUnpickleMessage<SetServoPosition>);
	vSetServoPosition.def_readwrite("id", &SetServoPosition::id);
	vSetServoPosition.def_readwrite("value", &SetServoPosition::value);
}