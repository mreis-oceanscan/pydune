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

void pbServoPosition(py::module &m) {
	auto vServoPosition = py::class_<ServoPosition, Message>(m, "ServoPosition", "Servo Position");
	vServoPosition.def(py::init<>());
	vServoPosition.def("__setstate__", &pbUnpickleMessage<ServoPosition>);
	vServoPosition.def_readwrite("id", &ServoPosition::id);
	vServoPosition.def_readwrite("value", &ServoPosition::value);
}