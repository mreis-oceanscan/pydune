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

void pbHistoricEvent(py::module &m) {
	auto vHistoricEvent = py::class_<HistoricEvent, Message>(m, "HistoricEvent", "Historic Event");
	vHistoricEvent.def(py::init<>());
	vHistoricEvent.def("__setstate__", &pbUnpickleMessage<HistoricEvent>);
	
	vHistoricEvent.def_property("text",
	    [](const HistoricEvent &x){return ascii_to_unicode_safe(x.text);},
	    [](HistoricEvent &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);
	
	vHistoricEvent.def_property("type",
	    [](const HistoricEvent &x){return static_cast<HistoricEvent::EventTypeEnum>(x.type);},
	    [](HistoricEvent *x, const uint8_t &y){x->type = y;},
	    "");

	py::enum_<HistoricEvent::EventTypeEnum>(vHistoricEvent, "EventTypeEnum", "Event Type")
		.value("INFO", HistoricEvent::EventTypeEnum::EVTYPE_INFO)
		.value("ERROR", HistoricEvent::EventTypeEnum::EVTYPE_ERROR);
}