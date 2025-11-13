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

void pbSoiState(py::module &m) {
	auto vSoiState = py::class_<SoiState, Message>(m, "SoiState", "SOI State");
	vSoiState.def(py::init<>());
	vSoiState.def("__setstate__", &pbUnpickleMessage<SoiState>);
	
	vSoiState.def_property("state",
	    [](const SoiState &x){return static_cast<SoiState::StateEnum>(x.state);},
	    [](SoiState *x, const uint8_t &y){x->state = y;},
	    "");
	vSoiState.def_readwrite("plan_id", &SoiState::plan_id);
	vSoiState.def_readwrite("wpt_id", &SoiState::wpt_id);
	vSoiState.def_readwrite("settings_chk", &SoiState::settings_chk);

	py::enum_<SoiState::StateEnum>(vSoiState, "StateEnum", "State")
		.value("EXEC", SoiState::StateEnum::SOISTATE_EXEC)
		.value("IDLE", SoiState::StateEnum::SOISTATE_IDLE)
		.value("INACTIVE", SoiState::StateEnum::SOISTATE_INACTIVE);
}