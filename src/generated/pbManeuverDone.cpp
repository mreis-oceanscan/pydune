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

void pbManeuverDone(py::module &m) {
	auto vManeuverDone = py::class_<ManeuverDone, Message>(m, "ManeuverDone", "Maneuver Done");
	vManeuverDone.def(py::init<>());
	vManeuverDone.def("__setstate__", &pbUnpickleMessage<ManeuverDone>);
}