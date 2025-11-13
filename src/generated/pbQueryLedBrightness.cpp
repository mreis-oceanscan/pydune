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

void pbQueryLedBrightness(py::module &m) {
	auto vQueryLedBrightness = py::class_<QueryLedBrightness, Message>(m, "QueryLedBrightness", "Query LED Brightness");
	vQueryLedBrightness.def(py::init<>());
	vQueryLedBrightness.def("__setstate__", &pbUnpickleMessage<QueryLedBrightness>);
	
	vQueryLedBrightness.def_property("name",
	    [](const QueryLedBrightness &x){return ascii_to_unicode_safe(x.name);},
	    [](QueryLedBrightness &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
}