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

void pbDevCalibrationControl(py::module &m) {
	auto vDevCalibrationControl = py::class_<DevCalibrationControl, Message>(m, "DevCalibrationControl", "Device Calibration Control");
	vDevCalibrationControl.def(py::init<>());
	vDevCalibrationControl.def("__setstate__", &pbUnpickleMessage<DevCalibrationControl>);
	
	vDevCalibrationControl.def_property("op",
	    [](const DevCalibrationControl &x){return static_cast<DevCalibrationControl::OperationEnum>(x.op);},
	    [](DevCalibrationControl *x, const uint8_t &y){x->op = y;},
	    "");

	py::enum_<DevCalibrationControl::OperationEnum>(vDevCalibrationControl, "OperationEnum", "Operation")
		.value("START", DevCalibrationControl::OperationEnum::DCAL_START)
		.value("STOP", DevCalibrationControl::OperationEnum::DCAL_STOP)
		.value("STEP_NEXT", DevCalibrationControl::OperationEnum::DCAL_STEP_NEXT)
		.value("STEP_PREVIOUS", DevCalibrationControl::OperationEnum::DCAL_STEP_PREVIOUS);
}