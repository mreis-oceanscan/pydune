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

void pbReportedState(py::module &m) {
	auto vReportedState = py::class_<ReportedState, Message>(m, "ReportedState", "Reported State");
	vReportedState.def(py::init<>());
	vReportedState.def("__setstate__", &pbUnpickleMessage<ReportedState>);
	vReportedState.def_readwrite("lat", &ReportedState::lat);
	vReportedState.def_readwrite("lon", &ReportedState::lon);
	vReportedState.def_readwrite("depth", &ReportedState::depth);
	vReportedState.def_readwrite("roll", &ReportedState::roll);
	vReportedState.def_readwrite("pitch", &ReportedState::pitch);
	vReportedState.def_readwrite("yaw", &ReportedState::yaw);
	vReportedState.def_readwrite("rcp_time", &ReportedState::rcp_time);
	
	vReportedState.def_property("sid",
	    [](const ReportedState &x){return ascii_to_unicode_safe(x.sid);},
	    [](ReportedState &x, std::string &s){x.sid = s;}, py::return_value_policy::take_ownership);
	
	vReportedState.def_property("s_type",
	    [](const ReportedState &x){return static_cast<ReportedState::SourceTypeEnum>(x.s_type);},
	    [](ReportedState *x, const uint8_t &y){x->s_type = y;},
	    "");

	py::enum_<ReportedState::SourceTypeEnum>(vReportedState, "SourceTypeEnum", "Source Type")
		.value("WI_FI", ReportedState::SourceTypeEnum::STYPE_WI_FI)
		.value("TRACKER", ReportedState::SourceTypeEnum::STYPE_TRACKER)
		.value("SMS", ReportedState::SourceTypeEnum::STYPE_SMS)
		.value("ACOUSTIC_MODEM", ReportedState::SourceTypeEnum::STYPE_ACOUSTIC_MODEM)
		.value("UNKNOWN", ReportedState::SourceTypeEnum::STYPE_UNKNOWN);
}