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

void pbAngularVelocity(py::module &m) {
	auto vAngularVelocity = py::class_<AngularVelocity, Message>(m, "AngularVelocity", "Angular Velocity");
	vAngularVelocity.def(py::init<>());
	vAngularVelocity.def("__setstate__", &pbUnpickleMessage<AngularVelocity>);
	vAngularVelocity.def_readwrite("time", &AngularVelocity::time);
	vAngularVelocity.def_readwrite("x", &AngularVelocity::x);
	vAngularVelocity.def_readwrite("y", &AngularVelocity::y);
	vAngularVelocity.def_readwrite("z", &AngularVelocity::z);
}