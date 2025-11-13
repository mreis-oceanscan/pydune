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

void pbDevCalibrationState(py::module &m) {
	auto vDevCalibrationState = py::class_<DevCalibrationState, Message>(m, "DevCalibrationState", "Device Calibration State");
	vDevCalibrationState.def(py::init<>());
	vDevCalibrationState.def("__setstate__", &pbUnpickleMessage<DevCalibrationState>);
	vDevCalibrationState.def_readwrite("total_steps", &DevCalibrationState::total_steps);
	vDevCalibrationState.def_readwrite("step_number", &DevCalibrationState::step_number);
	
	vDevCalibrationState.def_property("step",
	    [](const DevCalibrationState &x){return ascii_to_unicode_safe(x.step);},
	    [](DevCalibrationState &x, std::string &s){x.step = s;}, py::return_value_policy::take_ownership);
	vDevCalibrationState.def_readwrite("flags", &DevCalibrationState::flags);

	py::enum_<DevCalibrationState::FlagsBits>(vDevCalibrationState, "FlagsBits", "Flags", py::arithmetic())
		.value("PREVIOUS_NOT_SUPPORTED", DevCalibrationState::FlagsBits::DCS_PREVIOUS_NOT_SUPPORTED)
		.value("NEXT_NOT_SUPPORTED", DevCalibrationState::FlagsBits::DCS_NEXT_NOT_SUPPORTED)
		.value("WAITING_CONTROL", DevCalibrationState::FlagsBits::DCS_WAITING_CONTROL)
		.value("ERROR", DevCalibrationState::FlagsBits::DCS_ERROR)
		.value("COMPLETED", DevCalibrationState::FlagsBits::DCS_COMPLETED);
}