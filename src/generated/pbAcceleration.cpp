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

void pbAcceleration(py::module &m) {
	auto vAcceleration = py::class_<Acceleration, Message>(m, "Acceleration", "Acceleration");
	vAcceleration.def(py::init<>());
	vAcceleration.def("__setstate__", &pbUnpickleMessage<Acceleration>);
	vAcceleration.def_readwrite("time", &Acceleration::time);
	vAcceleration.def_readwrite("x", &Acceleration::x);
	vAcceleration.def_readwrite("y", &Acceleration::y);
	vAcceleration.def_readwrite("z", &Acceleration::z);
}