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

void pbCcuEvent(py::module &m) {
	auto vCcuEvent = py::class_<CcuEvent, Message>(m, "CcuEvent", "CCU Event");
	vCcuEvent.def(py::init<>());
	vCcuEvent.def("__setstate__", &pbUnpickleMessage<CcuEvent>);
	
	vCcuEvent.def_property("type",
	    [](const CcuEvent &x){return static_cast<CcuEvent::EventTypeEnum>(x.type);},
	    [](CcuEvent *x, const uint8_t &y){x->type = y;},
	    "");
	
	vCcuEvent.def_property("id",
	    [](const CcuEvent &x){return ascii_to_unicode_safe(x.id);},
	    [](CcuEvent &x, std::string &s){x.id = s;}, py::return_value_policy::take_ownership);
	
	vCcuEvent.def_property("arg",
	[](const CcuEvent &x){return x.arg.isNull() ? nullptr : x.arg.get();},
	[](CcuEvent *x, const py::handle &y){
	    if(y.is_none()){
	        x->arg.clear();
	    } else {
	        try {
	            x->arg.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->arg.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<CcuEvent::EventTypeEnum>(vCcuEvent, "EventTypeEnum", "Event Type")
		.value("LOG_ENTRY", CcuEvent::EventTypeEnum::EVT_LOG_ENTRY)
		.value("PLAN_ADDED", CcuEvent::EventTypeEnum::EVT_PLAN_ADDED)
		.value("PLAN_REMOVED", CcuEvent::EventTypeEnum::EVT_PLAN_REMOVED)
		.value("PLAN_CHANGED", CcuEvent::EventTypeEnum::EVT_PLAN_CHANGED)
		.value("MAP_FEATURE_ADDED", CcuEvent::EventTypeEnum::EVT_MAP_FEATURE_ADDED)
		.value("MAP_FEATURE_REMOVED", CcuEvent::EventTypeEnum::EVT_MAP_FEATURE_REMOVED)
		.value("MAP_FEATURE_CHANGED", CcuEvent::EventTypeEnum::EVT_MAP_FEATURE_CHANGED)
		.value("TELEOPERATION_STARTED", CcuEvent::EventTypeEnum::EVT_TELEOPERATION_STARTED)
		.value("TELEOPERATION_ENDED", CcuEvent::EventTypeEnum::EVT_TELEOPERATION_ENDED);
}