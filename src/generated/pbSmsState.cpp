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

void pbSmsState(py::module &m) {
	auto vSmsState = py::class_<SmsState, Message>(m, "SmsState", "SMS State");
	vSmsState.def(py::init<>());
	vSmsState.def("__setstate__", &pbUnpickleMessage<SmsState>);
	vSmsState.def_readwrite("seq", &SmsState::seq);
	
	vSmsState.def_property("state",
	    [](const SmsState &x){return static_cast<SmsState::StateEnum>(x.state);},
	    [](SmsState *x, const uint8_t &y){x->state = y;},
	    "");
	
	vSmsState.def_property("error",
	    [](const SmsState &x){return ascii_to_unicode_safe(x.error);},
	    [](SmsState &x, std::string &s){x.error = s;}, py::return_value_policy::take_ownership);

	py::enum_<SmsState::StateEnum>(vSmsState, "StateEnum", "State")
		.value("ACCEPTED", SmsState::StateEnum::SMS_ACCEPTED)
		.value("REJECTED", SmsState::StateEnum::SMS_REJECTED)
		.value("INTERRUPTED", SmsState::StateEnum::SMS_INTERRUPTED)
		.value("COMPLETED", SmsState::StateEnum::SMS_COMPLETED)
		.value("IDLE", SmsState::StateEnum::SMS_IDLE)
		.value("TRANSMITTING", SmsState::StateEnum::SMS_TRANSMITTING)
		.value("RECEIVING", SmsState::StateEnum::SMS_RECEIVING);
}