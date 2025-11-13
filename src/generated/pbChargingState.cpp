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

void pbChargingState(py::module &m) {
	auto vChargingState = py::class_<ChargingState, Message>(m, "ChargingState", "Charging State");
	vChargingState.def(py::init<>());
	vChargingState.def("__setstate__", &pbUnpickleMessage<ChargingState>);
	
	vChargingState.def_property("is_charging",
	    [](const ChargingState &x){return static_cast<ChargingState::IsChargingEnum>(x.is_charging);},
	    [](ChargingState *x, const uint8_t &y){x->is_charging = y;},
	    "");

	py::enum_<ChargingState::IsChargingEnum>(vChargingState, "IsChargingEnum", "Is Charging")
		.value("NOT_CHARGING", ChargingState::IsChargingEnum::CSTATE_NOT_CHARGING)
		.value("IS_CHARGING", ChargingState::IsChargingEnum::CSTATE_IS_CHARGING);
}