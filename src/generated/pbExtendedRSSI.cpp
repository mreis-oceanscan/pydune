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

void pbExtendedRSSI(py::module &m) {
	auto vExtendedRSSI = py::class_<ExtendedRSSI, Message>(m, "ExtendedRSSI", "Extended Receive Signal Strength Information");
	vExtendedRSSI.def(py::init<>());
	vExtendedRSSI.def("__setstate__", &pbUnpickleMessage<ExtendedRSSI>);
	vExtendedRSSI.def_readwrite("value", &ExtendedRSSI::value);
	
	vExtendedRSSI.def_property("units",
	    [](const ExtendedRSSI &x){return static_cast<RSSIUnits>(x.units);},
	    [](ExtendedRSSI *x, const uint8_t &y){x->units = y;},
	    "");
}