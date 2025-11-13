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

void pbApmStatus(py::module &m) {
	auto vApmStatus = py::class_<ApmStatus, Message>(m, "ApmStatus", "APM Status");
	vApmStatus.def(py::init<>());
	vApmStatus.def("__setstate__", &pbUnpickleMessage<ApmStatus>);
	
	vApmStatus.def_property("severity",
	    [](const ApmStatus &x){return static_cast<ApmStatus::SeverityEnum>(x.severity);},
	    [](ApmStatus *x, const uint8_t &y){x->severity = y;},
	    "");
	
	vApmStatus.def_property("text",
	    [](const ApmStatus &x){return ascii_to_unicode_safe(x.text);},
	    [](ApmStatus &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);

	py::enum_<ApmStatus::SeverityEnum>(vApmStatus, "SeverityEnum", "Severity")
		.value("EMERGENCY", ApmStatus::SeverityEnum::APM_EMERGENCY)
		.value("ALERT", ApmStatus::SeverityEnum::APM_ALERT)
		.value("CRITICAL", ApmStatus::SeverityEnum::APM_CRITICAL)
		.value("ERROR", ApmStatus::SeverityEnum::APM_ERROR)
		.value("WARNING", ApmStatus::SeverityEnum::APM_WARNING)
		.value("NOTICE", ApmStatus::SeverityEnum::APM_NOTICE)
		.value("INFO", ApmStatus::SeverityEnum::APM_INFO)
		.value("DEBUG", ApmStatus::SeverityEnum::APM_DEBUG);
}