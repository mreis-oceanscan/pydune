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

void pbVehicleState(py::module &m) {
	auto vVehicleState = py::class_<VehicleState, Message>(m, "VehicleState", "Vehicle State");
	vVehicleState.def(py::init<>());
	vVehicleState.def("__setstate__", &pbUnpickleMessage<VehicleState>);
	
	vVehicleState.def_property("op_mode",
	    [](const VehicleState &x){return static_cast<VehicleState::OperationModeEnum>(x.op_mode);},
	    [](VehicleState *x, const uint8_t &y){x->op_mode = y;},
	    "");
	vVehicleState.def_readwrite("error_count", &VehicleState::error_count);
	
	vVehicleState.def_property("error_ents",
	    [](const VehicleState &x){return ascii_to_unicode_safe(x.error_ents);},
	    [](VehicleState &x, std::string &s){x.error_ents = s;}, py::return_value_policy::take_ownership);
	vVehicleState.def_readwrite("maneuver_type", &VehicleState::maneuver_type);
	vVehicleState.def_readwrite("maneuver_stime", &VehicleState::maneuver_stime);
	vVehicleState.def_readwrite("maneuver_eta", &VehicleState::maneuver_eta);
	vVehicleState.def_readwrite("control_loops", &VehicleState::control_loops);
	vVehicleState.def_readwrite("flags", &VehicleState::flags);
	
	vVehicleState.def_property("last_error",
	    [](const VehicleState &x){return ascii_to_unicode_safe(x.last_error);},
	    [](VehicleState &x, std::string &s){x.last_error = s;}, py::return_value_policy::take_ownership);
	vVehicleState.def_readwrite("last_error_time", &VehicleState::last_error_time);

	py::enum_<VehicleState::OperationModeEnum>(vVehicleState, "OperationModeEnum", "Operation Mode")
		.value("SERVICE", VehicleState::OperationModeEnum::VS_SERVICE)
		.value("CALIBRATION", VehicleState::OperationModeEnum::VS_CALIBRATION)
		.value("ERROR", VehicleState::OperationModeEnum::VS_ERROR)
		.value("MANEUVER", VehicleState::OperationModeEnum::VS_MANEUVER)
		.value("EXTERNAL", VehicleState::OperationModeEnum::VS_EXTERNAL)
		.value("BOOT", VehicleState::OperationModeEnum::VS_BOOT);

	py::enum_<VehicleState::FlagsBits>(vVehicleState, "FlagsBits", "Flags", py::arithmetic())
		.value("MANEUVER_DONE", VehicleState::FlagsBits::VFLG_MANEUVER_DONE);
}