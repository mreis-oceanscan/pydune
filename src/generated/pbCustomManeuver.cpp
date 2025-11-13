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

void pbCustomManeuver(py::module &m) {
	auto vCustomManeuver = py::class_<CustomManeuver, Maneuver>(m, "CustomManeuver", "Custom Maneuver");
	vCustomManeuver.def(py::init<>());
	vCustomManeuver.def("__setstate__", &pbUnpickleMessage<CustomManeuver>);
	vCustomManeuver.def_readwrite("timeout", &CustomManeuver::timeout);
	
	vCustomManeuver.def_property("name",
	    [](const CustomManeuver &x){return ascii_to_unicode_safe(x.name);},
	    [](CustomManeuver &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vCustomManeuver.def_property("custom",
	    [](const CustomManeuver &x){return ascii_to_unicode_safe(x.custom);},
	    [](CustomManeuver &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}