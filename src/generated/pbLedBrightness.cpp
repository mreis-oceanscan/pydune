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

void pbLedBrightness(py::module &m) {
	auto vLedBrightness = py::class_<LedBrightness, Message>(m, "LedBrightness", "LED Brightness");
	vLedBrightness.def(py::init<>());
	vLedBrightness.def("__setstate__", &pbUnpickleMessage<LedBrightness>);
	
	vLedBrightness.def_property("name",
	    [](const LedBrightness &x){return ascii_to_unicode_safe(x.name);},
	    [](LedBrightness &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vLedBrightness.def_readwrite("value", &LedBrightness::value);
}