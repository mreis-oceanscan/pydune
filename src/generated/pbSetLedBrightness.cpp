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

void pbSetLedBrightness(py::module &m) {
	auto vSetLedBrightness = py::class_<SetLedBrightness, Message>(m, "SetLedBrightness", "Set LED Brightness");
	vSetLedBrightness.def(py::init<>());
	vSetLedBrightness.def("__setstate__", &pbUnpickleMessage<SetLedBrightness>);
	
	vSetLedBrightness.def_property("name",
	    [](const SetLedBrightness &x){return ascii_to_unicode_safe(x.name);},
	    [](SetLedBrightness &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vSetLedBrightness.def_readwrite("value", &SetLedBrightness::value);
}