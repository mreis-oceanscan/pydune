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

void pbDevDataText(py::module &m) {
	auto vDevDataText = py::class_<DevDataText, Message>(m, "DevDataText", "Device Data (Text)");
	vDevDataText.def(py::init<>());
	vDevDataText.def("__setstate__", &pbUnpickleMessage<DevDataText>);
	
	vDevDataText.def_property("value",
	    [](const DevDataText &x){return ascii_to_unicode_safe(x.value);},
	    [](DevDataText &x, std::string &s){x.value = s;}, py::return_value_policy::take_ownership);
}