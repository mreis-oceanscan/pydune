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

void pbCacheControl(py::module &m) {
	auto vCacheControl = py::class_<CacheControl, Message>(m, "CacheControl", "Cache Control");
	vCacheControl.def(py::init<>());
	vCacheControl.def("__setstate__", &pbUnpickleMessage<CacheControl>);
	
	vCacheControl.def_property("op",
	    [](const CacheControl &x){return static_cast<CacheControl::ControlOperationEnum>(x.op);},
	    [](CacheControl *x, const uint8_t &y){x->op = y;},
	    "");
	
	vCacheControl.def_property("snapshot",
	    [](const CacheControl &x){return ascii_to_unicode_safe(x.snapshot);},
	    [](CacheControl &x, std::string &s){x.snapshot = s;}, py::return_value_policy::take_ownership);
	
	vCacheControl.def_property("message",
	[](const CacheControl &x){return x.message.isNull() ? nullptr : x.message.get();},
	[](CacheControl *x, const py::handle &y){
	    if(y.is_none()){
	        x->message.clear();
	    } else {
	        try {
	            x->message.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->message.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<CacheControl::ControlOperationEnum>(vCacheControl, "ControlOperationEnum", "Control Operation")
		.value("STORE", CacheControl::ControlOperationEnum::COP_STORE)
		.value("LOAD", CacheControl::ControlOperationEnum::COP_LOAD)
		.value("CLEAR", CacheControl::ControlOperationEnum::COP_CLEAR)
		.value("COPY", CacheControl::ControlOperationEnum::COP_COPY)
		.value("COPY_COMPLETE", CacheControl::ControlOperationEnum::COP_COPY_COMPLETE);
}