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

void pbReportControl(py::module &m) {
	auto vReportControl = py::class_<ReportControl, Message>(m, "ReportControl", "Report Control");
	vReportControl.def(py::init<>());
	vReportControl.def("__setstate__", &pbUnpickleMessage<ReportControl>);
	
	vReportControl.def_property("op",
	    [](const ReportControl &x){return static_cast<ReportControl::OperationEnum>(x.op);},
	    [](ReportControl *x, const uint8_t &y){x->op = y;},
	    "");
	vReportControl.def_readwrite("comm_interface", &ReportControl::comm_interface);
	vReportControl.def_readwrite("period", &ReportControl::period);
	
	vReportControl.def_property("sys_dst",
	    [](const ReportControl &x){return ascii_to_unicode_safe(x.sys_dst);},
	    [](ReportControl &x, std::string &s){x.sys_dst = s;}, py::return_value_policy::take_ownership);

	py::enum_<ReportControl::OperationEnum>(vReportControl, "OperationEnum", "Operation")
		.value("REQUEST_START", ReportControl::OperationEnum::OP_REQUEST_START)
		.value("STARTED", ReportControl::OperationEnum::OP_STARTED)
		.value("REQUEST_STOP", ReportControl::OperationEnum::OP_REQUEST_STOP)
		.value("STOPPED", ReportControl::OperationEnum::OP_STOPPED)
		.value("REQUEST_REPORT", ReportControl::OperationEnum::OP_REQUEST_REPORT)
		.value("REPORT_SENT", ReportControl::OperationEnum::OP_REPORT_SENT);

	py::enum_<ReportControl::CommunicationInterfaceBits>(vReportControl, "CommunicationInterfaceBits", "Communication Interface", py::arithmetic())
		.value("ACOUSTIC", ReportControl::CommunicationInterfaceBits::CI_ACOUSTIC)
		.value("SATELLITE", ReportControl::CommunicationInterfaceBits::CI_SATELLITE)
		.value("GSM", ReportControl::CommunicationInterfaceBits::CI_GSM)
		.value("MOBILE", ReportControl::CommunicationInterfaceBits::CI_MOBILE)
		.value("RADIO", ReportControl::CommunicationInterfaceBits::CI_RADIO);
}