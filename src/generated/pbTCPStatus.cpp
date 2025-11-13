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

void pbTCPStatus(py::module &m) {
	auto vTCPStatus = py::class_<TCPStatus, Message>(m, "TCPStatus", "TCP Transmission Status");
	vTCPStatus.def(py::init<>());
	vTCPStatus.def("__setstate__", &pbUnpickleMessage<TCPStatus>);
	vTCPStatus.def_readwrite("req_id", &TCPStatus::req_id);
	
	vTCPStatus.def_property("status",
	    [](const TCPStatus &x){return static_cast<TCPStatus::StatusEnum>(x.status);},
	    [](TCPStatus *x, const uint8_t &y){x->status = y;},
	    "");
	
	vTCPStatus.def_property("info",
	    [](const TCPStatus &x){return ascii_to_unicode_safe(x.info);},
	    [](TCPStatus &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<TCPStatus::StatusEnum>(vTCPStatus, "StatusEnum", "Status")
		.value("QUEUED", TCPStatus::StatusEnum::TCPSTAT_QUEUED)
		.value("SENT", TCPStatus::StatusEnum::TCPSTAT_SENT)
		.value("INPUT_FAILURE", TCPStatus::StatusEnum::TCPSTAT_INPUT_FAILURE)
		.value("HOST_UNKNOWN", TCPStatus::StatusEnum::TCPSTAT_HOST_UNKNOWN)
		.value("CANT_CONNECT", TCPStatus::StatusEnum::TCPSTAT_CANT_CONNECT)
		.value("ERROR", TCPStatus::StatusEnum::TCPSTAT_ERROR);
}