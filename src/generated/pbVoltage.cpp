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

void pbVoltage(py::module &m) {
	auto vVoltage = py::class_<Voltage, Message>(m, "Voltage", "Voltage");
	vVoltage.def(py::init<>());
	vVoltage.def("__setstate__", &pbUnpickleMessage<Voltage>);
	vVoltage.def_readwrite("value", &Voltage::value);
}