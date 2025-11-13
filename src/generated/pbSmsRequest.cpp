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

void pbSmsRequest(py::module &m) {
	auto vSmsRequest = py::class_<SmsRequest, Message>(m, "SmsRequest", "SMS Transmission Request");
	vSmsRequest.def(py::init<>());
	vSmsRequest.def("__setstate__", &pbUnpickleMessage<SmsRequest>);
	vSmsRequest.def_readwrite("req_id", &SmsRequest::req_id);
	
	vSmsRequest.def_property("destination",
	    [](const SmsRequest &x){return ascii_to_unicode_safe(x.destination);},
	    [](SmsRequest &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	vSmsRequest.def_readwrite("timeout", &SmsRequest::timeout);
	
	vSmsRequest.def_property("sms_text",
	    [](const SmsRequest &x){return ascii_to_unicode_safe(x.sms_text);},
	    [](SmsRequest &x, std::string &s){x.sms_text = s;}, py::return_value_policy::take_ownership);
}