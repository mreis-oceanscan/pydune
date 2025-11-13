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

void pbSoiWaypoint(py::module &m) {
	auto vSoiWaypoint = py::class_<SoiWaypoint, Message>(m, "SoiWaypoint", "SOI Waypoint");
	vSoiWaypoint.def(py::init<>());
	vSoiWaypoint.def("__setstate__", &pbUnpickleMessage<SoiWaypoint>);
	vSoiWaypoint.def_readwrite("lat", &SoiWaypoint::lat);
	vSoiWaypoint.def_readwrite("lon", &SoiWaypoint::lon);
	vSoiWaypoint.def_readwrite("eta", &SoiWaypoint::eta);
	vSoiWaypoint.def_readwrite("duration", &SoiWaypoint::duration);
}