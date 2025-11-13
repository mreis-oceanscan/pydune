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

void pbHealthCheck(py::module &m) {
	auto vHealthCheck = py::class_<HealthCheck, Message>(m, "HealthCheck", "HealthCheck");
	vHealthCheck.def(py::init<>());
	vHealthCheck.def("__setstate__", &pbUnpickleMessage<HealthCheck>);
	
	vHealthCheck.def_property("op",
	    [](const HealthCheck &x){return static_cast<HealthCheck::OperationEnum>(x.op);},
	    [](HealthCheck *x, const uint8_t &y){x->op = y;},
	    "");
	vHealthCheck.def_readwrite("request_id", &HealthCheck::request_id);
	
	vHealthCheck.def_property("entity_name",
	    [](const HealthCheck &x){return ascii_to_unicode_safe(x.entity_name);},
	    [](HealthCheck &x, std::string &s){x.entity_name = s;}, py::return_value_policy::take_ownership);
	
	vHealthCheck.def_property("status",
	    [](const HealthCheck &x){return static_cast<HealthCheck::StatusEnum>(x.status);},
	    [](HealthCheck *x, const uint16_t &y){x->status = y;},
	    "");
	
	vHealthCheck.def_property("text",
	    [](const HealthCheck &x){return ascii_to_unicode_safe(x.text);},
	    [](HealthCheck &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);

	py::enum_<HealthCheck::OperationEnum>(vHealthCheck, "OperationEnum", "Operation")
		.value("REQUEST", HealthCheck::OperationEnum::OP_REQUEST)
		.value("REPLY", HealthCheck::OperationEnum::OP_REPLY)
		.value("QUERY", HealthCheck::OperationEnum::OP_QUERY);

	py::enum_<HealthCheck::StatusEnum>(vHealthCheck, "StatusEnum", "Status")
		.value("FINISHED_OK", HealthCheck::StatusEnum::ST_FINISHED_OK)
		.value("FINISHED_ERROR", HealthCheck::StatusEnum::ST_FINISHED_ERROR)
		.value("IN_PROGRESS", HealthCheck::StatusEnum::ST_IN_PROGRESS)
		.value("IMP", HealthCheck::StatusEnum::ST_IMP)
		.value("NOT_IMP", HealthCheck::StatusEnum::ST_NOT_IMP)
		.value("ABORT", HealthCheck::StatusEnum::ST_ABORT)
		.value("CONN_ERROR", HealthCheck::StatusEnum::ST_CONN_ERROR)
		.value("SEND_ERROR", HealthCheck::StatusEnum::ST_SEND_ERROR)
		.value("READ_ERROR", HealthCheck::StatusEnum::ST_READ_ERROR)
		.value("DEV_ERROR", HealthCheck::StatusEnum::ST_DEV_ERROR)
		.value("DISC_ERROR", HealthCheck::StatusEnum::ST_DISC_ERROR);
}