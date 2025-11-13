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

void pbEvent(py::module &m) {
	auto vEvent = py::class_<Event, Message>(m, "Event", "Event");
	vEvent.def(py::init<>());
	vEvent.def("__setstate__", &pbUnpickleMessage<Event>);
	
	vEvent.def_property("topic",
	    [](const Event &x){return ascii_to_unicode_safe(x.topic);},
	    [](Event &x, std::string &s){x.topic = s;}, py::return_value_policy::take_ownership);
	
	vEvent.def_property("data",
	    [](const Event &x){return ascii_to_unicode_safe(x.data);},
	    [](Event &x, std::string &s){x.data = s;}, py::return_value_policy::take_ownership);
}