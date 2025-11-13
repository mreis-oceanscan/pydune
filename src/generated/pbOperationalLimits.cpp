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

void pbOperationalLimits(py::module &m) {
	auto vOperationalLimits = py::class_<OperationalLimits, Message>(m, "OperationalLimits", "Operational Limits");
	vOperationalLimits.def(py::init<>());
	vOperationalLimits.def("__setstate__", &pbUnpickleMessage<OperationalLimits>);
	vOperationalLimits.def_readwrite("mask", &OperationalLimits::mask);
	vOperationalLimits.def_readwrite("max_depth", &OperationalLimits::max_depth);
	vOperationalLimits.def_readwrite("min_altitude", &OperationalLimits::min_altitude);
	vOperationalLimits.def_readwrite("max_altitude", &OperationalLimits::max_altitude);
	vOperationalLimits.def_readwrite("min_speed", &OperationalLimits::min_speed);
	vOperationalLimits.def_readwrite("max_speed", &OperationalLimits::max_speed);
	vOperationalLimits.def_readwrite("max_vrate", &OperationalLimits::max_vrate);
	vOperationalLimits.def_readwrite("lat", &OperationalLimits::lat);
	vOperationalLimits.def_readwrite("lon", &OperationalLimits::lon);
	vOperationalLimits.def_readwrite("orientation", &OperationalLimits::orientation);
	vOperationalLimits.def_readwrite("width", &OperationalLimits::width);
	vOperationalLimits.def_readwrite("length", &OperationalLimits::length);
}