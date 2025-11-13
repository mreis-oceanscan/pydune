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

void pbEulerAnglesDelta(py::module &m) {
	auto vEulerAnglesDelta = py::class_<EulerAnglesDelta, Message>(m, "EulerAnglesDelta", "Euler Angles Delta");
	vEulerAnglesDelta.def(py::init<>());
	vEulerAnglesDelta.def("__setstate__", &pbUnpickleMessage<EulerAnglesDelta>);
	vEulerAnglesDelta.def_readwrite("time", &EulerAnglesDelta::time);
	vEulerAnglesDelta.def_readwrite("x", &EulerAnglesDelta::x);
	vEulerAnglesDelta.def_readwrite("y", &EulerAnglesDelta::y);
	vEulerAnglesDelta.def_readwrite("z", &EulerAnglesDelta::z);
	vEulerAnglesDelta.def_readwrite("timestep", &EulerAnglesDelta::timestep);
}