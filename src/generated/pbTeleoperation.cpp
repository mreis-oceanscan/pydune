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

void pbTeleoperation(py::module &m) {
	auto vTeleoperation = py::class_<Teleoperation, Maneuver>(m, "Teleoperation", "Teleoperation Maneuver");
	vTeleoperation.def(py::init<>());
	vTeleoperation.def("__setstate__", &pbUnpickleMessage<Teleoperation>);
	
	vTeleoperation.def_property("custom",
	    [](const Teleoperation &x){return ascii_to_unicode_safe(x.custom);},
	    [](Teleoperation &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}