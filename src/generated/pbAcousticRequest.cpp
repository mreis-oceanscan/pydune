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

void pbAcousticRequest(py::module &m) {
	auto vAcousticRequest = py::class_<AcousticRequest, Message>(m, "AcousticRequest", "Acoustic Transmission Request");
	vAcousticRequest.def(py::init<>());
	vAcousticRequest.def("__setstate__", &pbUnpickleMessage<AcousticRequest>);
	vAcousticRequest.def_readwrite("req_id", &AcousticRequest::req_id);
	
	vAcousticRequest.def_property("destination",
	    [](const AcousticRequest &x){return ascii_to_unicode_safe(x.destination);},
	    [](AcousticRequest &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	vAcousticRequest.def_readwrite("timeout", &AcousticRequest::timeout);
	vAcousticRequest.def_readwrite("range", &AcousticRequest::range);
	
	vAcousticRequest.def_property("type",
	    [](const AcousticRequest &x){return static_cast<AcousticRequest::TypeEnum>(x.type);},
	    [](AcousticRequest *x, const uint8_t &y){x->type = y;},
	    "");
	
	vAcousticRequest.def_property("msg",
	[](const AcousticRequest &x){return x.msg.isNull() ? nullptr : x.msg.get();},
	[](AcousticRequest *x, const py::handle &y){
	    if(y.is_none()){
	        x->msg.clear();
	    } else {
	        try {
	            x->msg.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->msg.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<AcousticRequest::TypeEnum>(vAcousticRequest, "TypeEnum", "Type")
		.value("ABORT", AcousticRequest::TypeEnum::TYPE_ABORT)
		.value("RANGE", AcousticRequest::TypeEnum::TYPE_RANGE)
		.value("REVERSE_RANGE", AcousticRequest::TypeEnum::TYPE_REVERSE_RANGE)
		.value("MSG", AcousticRequest::TypeEnum::TYPE_MSG)
		.value("RAW", AcousticRequest::TypeEnum::TYPE_RAW);
}