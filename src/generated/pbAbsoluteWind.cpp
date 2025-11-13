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

void pbAbsoluteWind(py::module &m) {
	auto vAbsoluteWind = py::class_<AbsoluteWind, Message>(m, "AbsoluteWind", "Absolute Wind");
	vAbsoluteWind.def(py::init<>());
	vAbsoluteWind.def("__setstate__", &pbUnpickleMessage<AbsoluteWind>);
	vAbsoluteWind.def_readwrite("direction", &AbsoluteWind::direction);
	vAbsoluteWind.def_readwrite("speed", &AbsoluteWind::speed);
	vAbsoluteWind.def_readwrite("turbulence", &AbsoluteWind::turbulence);
}