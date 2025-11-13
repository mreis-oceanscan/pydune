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

void pbHistoricTelemetry(py::module &m) {
	auto vHistoricTelemetry = py::class_<HistoricTelemetry, Message>(m, "HistoricTelemetry", "Historic Telemetry");
	vHistoricTelemetry.def(py::init<>());
	vHistoricTelemetry.def("__setstate__", &pbUnpickleMessage<HistoricTelemetry>);
	vHistoricTelemetry.def_readwrite("altitude", &HistoricTelemetry::altitude);
	vHistoricTelemetry.def_readwrite("roll", &HistoricTelemetry::roll);
	vHistoricTelemetry.def_readwrite("pitch", &HistoricTelemetry::pitch);
	vHistoricTelemetry.def_readwrite("yaw", &HistoricTelemetry::yaw);
	vHistoricTelemetry.def_readwrite("speed", &HistoricTelemetry::speed);
}