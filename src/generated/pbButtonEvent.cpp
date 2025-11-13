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

void pbButtonEvent(py::module &m) {
	auto vButtonEvent = py::class_<ButtonEvent, Message>(m, "ButtonEvent", "Button Event");
	vButtonEvent.def(py::init<>());
	vButtonEvent.def("__setstate__", &pbUnpickleMessage<ButtonEvent>);
	vButtonEvent.def_readwrite("button", &ButtonEvent::button);
	vButtonEvent.def_readwrite("value", &ButtonEvent::value);
}