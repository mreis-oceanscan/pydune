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

void pbTelemetryMsg(py::module &m) {
	auto vTelemetryMsg = py::class_<TelemetryMsg, Message>(m, "TelemetryMsg", "Telemetry Message");
	vTelemetryMsg.def(py::init<>());
	vTelemetryMsg.def("__setstate__", &pbUnpickleMessage<TelemetryMsg>);
	
	vTelemetryMsg.def_property("type",
	    [](const TelemetryMsg &x){return static_cast<TelemetryMsg::TypeEnum>(x.type);},
	    [](TelemetryMsg *x, const uint8_t &y){x->type = y;},
	    "");
	vTelemetryMsg.def_readwrite("req_id", &TelemetryMsg::req_id);
	vTelemetryMsg.def_readwrite("ttl", &TelemetryMsg::ttl);
	
	vTelemetryMsg.def_property("code",
	    [](const TelemetryMsg &x){return static_cast<TelemetryMsg::CodeEnum>(x.code);},
	    [](TelemetryMsg *x, const uint8_t &y){x->code = y;},
	    "");
	
	vTelemetryMsg.def_property("destination",
	    [](const TelemetryMsg &x){return ascii_to_unicode_safe(x.destination);},
	    [](TelemetryMsg &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	
	vTelemetryMsg.def_property("source",
	    [](const TelemetryMsg &x){return ascii_to_unicode_safe(x.source);},
	    [](TelemetryMsg &x, std::string &s){x.source = s;}, py::return_value_policy::take_ownership);
	vTelemetryMsg.def_readwrite("acknowledge", &TelemetryMsg::acknowledge);
	
	vTelemetryMsg.def_property("status",
	    [](const TelemetryMsg &x){return static_cast<TelemetryMsg::StatusEnum>(x.status);},
	    [](TelemetryMsg *x, const uint8_t &y){x->status = y;},
	    "");
	
	vTelemetryMsg.def_property("data",
	    [](const TelemetryMsg &x){return py::bytes(x.data.data(), x.data.size());},
	    [](TelemetryMsg &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);

	py::enum_<TelemetryMsg::TypeEnum>(vTelemetryMsg, "TypeEnum", "Type")
		.value("TX", TelemetryMsg::TypeEnum::TM_TX)
		.value("RX", TelemetryMsg::TypeEnum::TM_RX)
		.value("TXSTATUS", TelemetryMsg::TypeEnum::TM_TXSTATUS);

	py::enum_<TelemetryMsg::CodeEnum>(vTelemetryMsg, "CodeEnum", "Code")
		.value("CODE_UNK", TelemetryMsg::CodeEnum::TM_CODE_UNK)
		.value("CODE_REPORT", TelemetryMsg::CodeEnum::TM_CODE_REPORT)
		.value("CODE_IMC", TelemetryMsg::CodeEnum::TM_CODE_IMC)
		.value("CODE_RAW", TelemetryMsg::CodeEnum::TM_CODE_RAW);

	py::enum_<TelemetryMsg::AcknowledgeBits>(vTelemetryMsg, "AcknowledgeBits", "Acknowledge", py::arithmetic())
		.value("NAK", TelemetryMsg::AcknowledgeBits::TM_NAK)
		.value("AK", TelemetryMsg::AcknowledgeBits::TM_AK);

	py::enum_<TelemetryMsg::StatusEnum>(vTelemetryMsg, "StatusEnum", "Status")
		.value("NONE", TelemetryMsg::StatusEnum::TM_NONE)
		.value("DONE", TelemetryMsg::StatusEnum::TM_DONE)
		.value("FAILED", TelemetryMsg::StatusEnum::TM_FAILED)
		.value("QUEUED", TelemetryMsg::StatusEnum::TM_QUEUED)
		.value("TRANSMIT", TelemetryMsg::StatusEnum::TM_TRANSMIT)
		.value("EXPIRED", TelemetryMsg::StatusEnum::TM_EXPIRED)
		.value("EMPTY", TelemetryMsg::StatusEnum::TM_EMPTY)
		.value("INV_ADDR", TelemetryMsg::StatusEnum::TM_INV_ADDR)
		.value("INV_SIZE", TelemetryMsg::StatusEnum::TM_INV_SIZE);
}