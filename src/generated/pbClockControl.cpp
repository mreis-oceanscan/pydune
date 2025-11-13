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

void pbClockControl(py::module &m) {
	auto vClockControl = py::class_<ClockControl, Message>(m, "ClockControl", "Clock Control");
	vClockControl.def(py::init<>());
	vClockControl.def("__setstate__", &pbUnpickleMessage<ClockControl>);
	
	vClockControl.def_property("op",
	    [](const ClockControl &x){return static_cast<ClockControl::OperationEnum>(x.op);},
	    [](ClockControl *x, const uint8_t &y){x->op = y;},
	    "");
	vClockControl.def_readwrite("clock", &ClockControl::clock);
	vClockControl.def_readwrite("tz", &ClockControl::tz);

	py::enum_<ClockControl::OperationEnum>(vClockControl, "OperationEnum", "Operation")
		.value("SYNC_EXEC", ClockControl::OperationEnum::COP_SYNC_EXEC)
		.value("SYNC_REQUEST", ClockControl::OperationEnum::COP_SYNC_REQUEST)
		.value("SYNC_STARTED", ClockControl::OperationEnum::COP_SYNC_STARTED)
		.value("SYNC_DONE", ClockControl::OperationEnum::COP_SYNC_DONE)
		.value("SET_TZ", ClockControl::OperationEnum::COP_SET_TZ)
		.value("SET_TZ_DONE", ClockControl::OperationEnum::COP_SET_TZ_DONE);
}