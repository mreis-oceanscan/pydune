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

void pbRSSI(py::module &m) {
	auto vRSSI = py::class_<RSSI, Message>(m, "RSSI", "Receive Signal Strength Information");
	vRSSI.def(py::init<>());
	vRSSI.def("__setstate__", &pbUnpickleMessage<RSSI>);
	vRSSI.def_readwrite("value", &RSSI::value);
}