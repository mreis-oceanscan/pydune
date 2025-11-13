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

void pbTextMessage(py::module &m) {
	auto vTextMessage = py::class_<TextMessage, Message>(m, "TextMessage", "Text Message");
	vTextMessage.def(py::init<>());
	vTextMessage.def("__setstate__", &pbUnpickleMessage<TextMessage>);
	
	vTextMessage.def_property("origin",
	    [](const TextMessage &x){return ascii_to_unicode_safe(x.origin);},
	    [](TextMessage &x, std::string &s){x.origin = s;}, py::return_value_policy::take_ownership);
	
	vTextMessage.def_property("text",
	    [](const TextMessage &x){return ascii_to_unicode_safe(x.text);},
	    [](TextMessage &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);
}