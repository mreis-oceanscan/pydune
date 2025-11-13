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

void pbAcousticStatus(py::module &m) {
	auto vAcousticStatus = py::class_<AcousticStatus, Message>(m, "AcousticStatus", "Acoustic Transmission Status");
	vAcousticStatus.def(py::init<>());
	vAcousticStatus.def("__setstate__", &pbUnpickleMessage<AcousticStatus>);
	vAcousticStatus.def_readwrite("req_id", &AcousticStatus::req_id);
	
	vAcousticStatus.def_property("type",
	    [](const AcousticStatus &x){return static_cast<AcousticStatus::TypeEnum>(x.type);},
	    [](AcousticStatus *x, const uint8_t &y){x->type = y;},
	    "");
	
	vAcousticStatus.def_property("status",
	    [](const AcousticStatus &x){return static_cast<AcousticStatus::StatusEnum>(x.status);},
	    [](AcousticStatus *x, const uint8_t &y){x->status = y;},
	    "");
	
	vAcousticStatus.def_property("info",
	    [](const AcousticStatus &x){return ascii_to_unicode_safe(x.info);},
	    [](AcousticStatus &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);
	vAcousticStatus.def_readwrite("range", &AcousticStatus::range);

	py::enum_<AcousticStatus::TypeEnum>(vAcousticStatus, "TypeEnum", "Type")
		.value("ABORT", AcousticStatus::TypeEnum::TYPE_ABORT)
		.value("RANGE", AcousticStatus::TypeEnum::TYPE_RANGE)
		.value("REVERSE_RANGE", AcousticStatus::TypeEnum::TYPE_REVERSE_RANGE)
		.value("MSG", AcousticStatus::TypeEnum::TYPE_MSG)
		.value("RAW", AcousticStatus::TypeEnum::TYPE_RAW);

	py::enum_<AcousticStatus::StatusEnum>(vAcousticStatus, "StatusEnum", "Status")
		.value("QUEUED", AcousticStatus::StatusEnum::STATUS_QUEUED)
		.value("IN_PROGRESS", AcousticStatus::StatusEnum::STATUS_IN_PROGRESS)
		.value("SENT", AcousticStatus::StatusEnum::STATUS_SENT)
		.value("RANGE_RECEIVED", AcousticStatus::StatusEnum::STATUS_RANGE_RECEIVED)
		.value("DELIVERED", AcousticStatus::StatusEnum::STATUS_DELIVERED)
		.value("BUSY", AcousticStatus::StatusEnum::STATUS_BUSY)
		.value("INPUT_FAILURE", AcousticStatus::StatusEnum::STATUS_INPUT_FAILURE)
		.value("ERROR", AcousticStatus::StatusEnum::STATUS_ERROR)
		.value("INV_ADDR", AcousticStatus::StatusEnum::STATUS_INV_ADDR)
		.value("UNSUPPORTED", AcousticStatus::StatusEnum::STATUS_UNSUPPORTED);
}