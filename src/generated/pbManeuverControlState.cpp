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

void pbManeuverControlState(py::module &m) {
	auto vManeuverControlState = py::class_<ManeuverControlState, Message>(m, "ManeuverControlState", "Maneuver Control State");
	vManeuverControlState.def(py::init<>());
	vManeuverControlState.def("__setstate__", &pbUnpickleMessage<ManeuverControlState>);
	
	vManeuverControlState.def_property("state",
	    [](const ManeuverControlState &x){return static_cast<ManeuverControlState::StateEnum>(x.state);},
	    [](ManeuverControlState *x, const uint8_t &y){x->state = y;},
	    "");
	vManeuverControlState.def_readwrite("eta", &ManeuverControlState::eta);
	
	vManeuverControlState.def_property("info",
	    [](const ManeuverControlState &x){return ascii_to_unicode_safe(x.info);},
	    [](ManeuverControlState &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<ManeuverControlState::StateEnum>(vManeuverControlState, "StateEnum", "State")
		.value("EXECUTING", ManeuverControlState::StateEnum::MCS_EXECUTING)
		.value("DONE", ManeuverControlState::StateEnum::MCS_DONE)
		.value("ERROR", ManeuverControlState::StateEnum::MCS_ERROR)
		.value("STOPPED", ManeuverControlState::StateEnum::MCS_STOPPED);
}