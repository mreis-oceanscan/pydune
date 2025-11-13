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

void pbGroupStreamVelocity(py::module &m) {
	auto vGroupStreamVelocity = py::class_<GroupStreamVelocity, Message>(m, "GroupStreamVelocity", "GroupStreamVelocity");
	vGroupStreamVelocity.def(py::init<>());
	vGroupStreamVelocity.def("__setstate__", &pbUnpickleMessage<GroupStreamVelocity>);
	vGroupStreamVelocity.def_readwrite("x", &GroupStreamVelocity::x);
	vGroupStreamVelocity.def_readwrite("y", &GroupStreamVelocity::y);
	vGroupStreamVelocity.def_readwrite("z", &GroupStreamVelocity::z);
}