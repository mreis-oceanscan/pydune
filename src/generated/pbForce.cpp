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

void pbForce(py::module &m) {
	auto vForce = py::class_<Force, Message>(m, "Force", "Force");
	vForce.def(py::init<>());
	vForce.def("__setstate__", &pbUnpickleMessage<Force>);
	vForce.def_readwrite("value", &Force::value);
}