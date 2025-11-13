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

void pbSmsStatus(py::module &m) {
	auto vSmsStatus = py::class_<SmsStatus, Message>(m, "SmsStatus", "SMS Transmission Status");
	vSmsStatus.def(py::init<>());
	vSmsStatus.def("__setstate__", &pbUnpickleMessage<SmsStatus>);
	vSmsStatus.def_readwrite("req_id", &SmsStatus::req_id);
	
	vSmsStatus.def_property("status",
	    [](const SmsStatus &x){return static_cast<SmsStatus::StatusEnum>(x.status);},
	    [](SmsStatus *x, const uint8_t &y){x->status = y;},
	    "");
	
	vSmsStatus.def_property("info",
	    [](const SmsStatus &x){return ascii_to_unicode_safe(x.info);},
	    [](SmsStatus &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<SmsStatus::StatusEnum>(vSmsStatus, "StatusEnum", "Status")
		.value("QUEUED", SmsStatus::StatusEnum::SMSSTAT_QUEUED)
		.value("SENT", SmsStatus::StatusEnum::SMSSTAT_SENT)
		.value("INPUT_FAILURE", SmsStatus::StatusEnum::SMSSTAT_INPUT_FAILURE)
		.value("ERROR", SmsStatus::StatusEnum::SMSSTAT_ERROR);
}