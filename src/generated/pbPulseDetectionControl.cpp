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

void pbPulseDetectionControl(py::module &m) {
	auto vPulseDetectionControl = py::class_<PulseDetectionControl, Message>(m, "PulseDetectionControl", "Pulse Detection Control");
	vPulseDetectionControl.def(py::init<>());
	vPulseDetectionControl.def("__setstate__", &pbUnpickleMessage<PulseDetectionControl>);
	
	vPulseDetectionControl.def_property("op",
	    [](const PulseDetectionControl &x){return static_cast<PulseDetectionControl::OperationEnum>(x.op);},
	    [](PulseDetectionControl *x, const uint8_t &y){x->op = y;},
	    "");

	py::enum_<PulseDetectionControl::OperationEnum>(vPulseDetectionControl, "OperationEnum", "Operation")
		.value("OFF", PulseDetectionControl::OperationEnum::POP_OFF)
		.value("ON", PulseDetectionControl::OperationEnum::POP_ON);
}