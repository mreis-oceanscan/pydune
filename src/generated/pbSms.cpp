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

void pbSms(py::module &m) {
	auto vSms = py::class_<Sms, Message>(m, "Sms", "SMS");
	vSms.def(py::init<>());
	vSms.def("__setstate__", &pbUnpickleMessage<Sms>);
	
	vSms.def_property("number",
	    [](const Sms &x){return ascii_to_unicode_safe(x.number);},
	    [](Sms &x, std::string &s){x.number = s;}, py::return_value_policy::take_ownership);
	vSms.def_readwrite("timeout", &Sms::timeout);
	
	vSms.def_property("contents",
	    [](const Sms &x){return ascii_to_unicode_safe(x.contents);},
	    [](Sms &x, std::string &s){x.contents = s;}, py::return_value_policy::take_ownership);
}