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

void pbIridiumTxStatus(py::module &m) {
	auto vIridiumTxStatus = py::class_<IridiumTxStatus, Message>(m, "IridiumTxStatus", "Iridium Transmission Status");
	vIridiumTxStatus.def(py::init<>());
	vIridiumTxStatus.def("__setstate__", &pbUnpickleMessage<IridiumTxStatus>);
	vIridiumTxStatus.def_readwrite("req_id", &IridiumTxStatus::req_id);
	
	vIridiumTxStatus.def_property("status",
	    [](const IridiumTxStatus &x){return static_cast<IridiumTxStatus::StatusCodeEnum>(x.status);},
	    [](IridiumTxStatus *x, const uint8_t &y){x->status = y;},
	    "");
	
	vIridiumTxStatus.def_property("text",
	    [](const IridiumTxStatus &x){return ascii_to_unicode_safe(x.text);},
	    [](IridiumTxStatus &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);

	py::enum_<IridiumTxStatus::StatusCodeEnum>(vIridiumTxStatus, "StatusCodeEnum", "Status Code")
		.value("OK", IridiumTxStatus::StatusCodeEnum::TXSTATUS_OK)
		.value("ERROR", IridiumTxStatus::StatusCodeEnum::TXSTATUS_ERROR)
		.value("QUEUED", IridiumTxStatus::StatusCodeEnum::TXSTATUS_QUEUED)
		.value("TRANSMIT", IridiumTxStatus::StatusCodeEnum::TXSTATUS_TRANSMIT)
		.value("EXPIRED", IridiumTxStatus::StatusCodeEnum::TXSTATUS_EXPIRED)
		.value("EMPTY", IridiumTxStatus::StatusCodeEnum::TXSTATUS_EMPTY);
}