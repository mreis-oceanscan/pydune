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

void pbDesiredPitch(py::module &m) {
	auto vDesiredPitch = py::class_<DesiredPitch, ControlCommand>(m, "DesiredPitch", "Desired Pitch");
	vDesiredPitch.def(py::init<>());
	vDesiredPitch.def("__setstate__", &pbUnpickleMessage<DesiredPitch>);
	vDesiredPitch.def_readwrite("value", &DesiredPitch::value);
}