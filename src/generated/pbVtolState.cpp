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

void pbVtolState(py::module &m) {
	auto vVtolState = py::class_<VtolState, Message>(m, "VtolState", "VTOL State");
	vVtolState.def(py::init<>());
	vVtolState.def("__setstate__", &pbUnpickleMessage<VtolState>);
	
	vVtolState.def_property("state",
	    [](const VtolState &x){return static_cast<VtolState::StateEnum>(x.state);},
	    [](VtolState *x, const uint8_t &y){x->state = y;},
	    "");

	py::enum_<VtolState::StateEnum>(vVtolState, "StateEnum", "State")
		.value("UNDEFINED", VtolState::StateEnum::VTOL_STATE_UNDEFINED)
		.value("TRANSITION_TO_FW", VtolState::StateEnum::VTOL_STATE_TRANSITION_TO_FW)
		.value("TRANSITION_TO_MC", VtolState::StateEnum::VTOL_STATE_TRANSITION_TO_MC)
		.value("MC", VtolState::StateEnum::VTOL_STATE_MC)
		.value("FW", VtolState::StateEnum::VTOL_STATE_FW);
}