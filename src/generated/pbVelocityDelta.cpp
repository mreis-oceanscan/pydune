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

void pbVelocityDelta(py::module &m) {
	auto vVelocityDelta = py::class_<VelocityDelta, Message>(m, "VelocityDelta", "Velocity Delta");
	vVelocityDelta.def(py::init<>());
	vVelocityDelta.def("__setstate__", &pbUnpickleMessage<VelocityDelta>);
	vVelocityDelta.def_readwrite("time", &VelocityDelta::time);
	vVelocityDelta.def_readwrite("x", &VelocityDelta::x);
	vVelocityDelta.def_readwrite("y", &VelocityDelta::y);
	vVelocityDelta.def_readwrite("z", &VelocityDelta::z);
}