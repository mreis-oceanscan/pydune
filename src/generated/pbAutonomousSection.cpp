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

void pbAutonomousSection(py::module &m) {
	auto vAutonomousSection = py::class_<AutonomousSection, Maneuver>(m, "AutonomousSection", "Autonomous Section");
	vAutonomousSection.def(py::init<>());
	vAutonomousSection.def("__setstate__", &pbUnpickleMessage<AutonomousSection>);
	vAutonomousSection.def_readwrite("lat", &AutonomousSection::lat);
	vAutonomousSection.def_readwrite("lon", &AutonomousSection::lon);
	vAutonomousSection.def_readwrite("speed", &AutonomousSection::speed);
	
	vAutonomousSection.def_property("speed_units",
	    [](const AutonomousSection &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](AutonomousSection *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vAutonomousSection.def_readwrite("limits", &AutonomousSection::limits);
	vAutonomousSection.def_readwrite("max_depth", &AutonomousSection::max_depth);
	vAutonomousSection.def_readwrite("min_alt", &AutonomousSection::min_alt);
	vAutonomousSection.def_readwrite("time_limit", &AutonomousSection::time_limit);
	vAutonomousSection.def_readwrite("area_limits", &AutonomousSection::area_limits);
	
	vAutonomousSection.def_property("controller",
	    [](const AutonomousSection &x){return ascii_to_unicode_safe(x.controller);},
	    [](AutonomousSection &x, std::string &s){x.controller = s;}, py::return_value_policy::take_ownership);
	
	vAutonomousSection.def_property("custom",
	    [](const AutonomousSection &x){return ascii_to_unicode_safe(x.custom);},
	    [](AutonomousSection &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<AutonomousSection::EnforcedLimitsBits>(vAutonomousSection, "EnforcedLimitsBits", "Enforced Limits", py::arithmetic())
		.value("DEPTH", AutonomousSection::EnforcedLimitsBits::ENFORCE_DEPTH)
		.value("ALTITUDE", AutonomousSection::EnforcedLimitsBits::ENFORCE_ALTITUDE)
		.value("TIMEOUT", AutonomousSection::EnforcedLimitsBits::ENFORCE_TIMEOUT)
		.value("AREA2D", AutonomousSection::EnforcedLimitsBits::ENFORCE_AREA2D);
}