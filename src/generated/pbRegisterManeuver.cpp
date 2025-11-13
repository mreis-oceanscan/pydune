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

void pbRegisterManeuver(py::module &m) {
	auto vRegisterManeuver = py::class_<RegisterManeuver, Message>(m, "RegisterManeuver", "Register Maneuver");
	vRegisterManeuver.def(py::init<>());
	vRegisterManeuver.def("__setstate__", &pbUnpickleMessage<RegisterManeuver>);
	vRegisterManeuver.def_readwrite("mid", &RegisterManeuver::mid);
}