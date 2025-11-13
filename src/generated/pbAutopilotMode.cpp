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

void pbAutopilotMode(py::module &m) {
	auto vAutopilotMode = py::class_<AutopilotMode, Message>(m, "AutopilotMode", "Autopilot Mode");
	vAutopilotMode.def(py::init<>());
	vAutopilotMode.def("__setstate__", &pbUnpickleMessage<AutopilotMode>);
	
	vAutopilotMode.def_property("autonomy",
	    [](const AutopilotMode &x){return static_cast<AutopilotMode::AutonomyLevelEnum>(x.autonomy);},
	    [](AutopilotMode *x, const uint8_t &y){x->autonomy = y;},
	    "");
	
	vAutopilotMode.def_property("mode",
	    [](const AutopilotMode &x){return ascii_to_unicode_safe(x.mode);},
	    [](AutopilotMode &x, std::string &s){x.mode = s;}, py::return_value_policy::take_ownership);

	py::enum_<AutopilotMode::AutonomyLevelEnum>(vAutopilotMode, "AutonomyLevelEnum", "Autonomy Level")
		.value("MANUAL", AutopilotMode::AutonomyLevelEnum::AL_MANUAL)
		.value("ASSISTED", AutopilotMode::AutonomyLevelEnum::AL_ASSISTED)
		.value("AUTO", AutopilotMode::AutonomyLevelEnum::AL_AUTO);
}