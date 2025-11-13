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

void pbPowerChannelState(py::module &m) {
	auto vPowerChannelState = py::class_<PowerChannelState, Message>(m, "PowerChannelState", "Power Channel State");
	vPowerChannelState.def(py::init<>());
	vPowerChannelState.def("__setstate__", &pbUnpickleMessage<PowerChannelState>);
	
	vPowerChannelState.def_property("name",
	    [](const PowerChannelState &x){return ascii_to_unicode_safe(x.name);},
	    [](PowerChannelState &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vPowerChannelState.def_property("state",
	    [](const PowerChannelState &x){return static_cast<PowerChannelState::StateEnum>(x.state);},
	    [](PowerChannelState *x, const uint8_t &y){x->state = y;},
	    "");

	py::enum_<PowerChannelState::StateEnum>(vPowerChannelState, "StateEnum", "State")
		.value("OFF", PowerChannelState::StateEnum::PCS_OFF)
		.value("ON", PowerChannelState::StateEnum::PCS_ON);
}