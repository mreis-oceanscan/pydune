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

void pbTransmissionStatus(py::module &m) {
	auto vTransmissionStatus = py::class_<TransmissionStatus, Message>(m, "TransmissionStatus", "Transmission Status");
	vTransmissionStatus.def(py::init<>());
	vTransmissionStatus.def("__setstate__", &pbUnpickleMessage<TransmissionStatus>);
	vTransmissionStatus.def_readwrite("req_id", &TransmissionStatus::req_id);
	
	vTransmissionStatus.def_property("status",
	    [](const TransmissionStatus &x){return static_cast<TransmissionStatus::StatusEnum>(x.status);},
	    [](TransmissionStatus *x, const uint8_t &y){x->status = y;},
	    "");
	vTransmissionStatus.def_readwrite("range", &TransmissionStatus::range);
	
	vTransmissionStatus.def_property("info",
	    [](const TransmissionStatus &x){return ascii_to_unicode_safe(x.info);},
	    [](TransmissionStatus &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<TransmissionStatus::StatusEnum>(vTransmissionStatus, "StatusEnum", "Status")
		.value("IN_PROGRESS", TransmissionStatus::StatusEnum::TSTAT_IN_PROGRESS)
		.value("SENT", TransmissionStatus::StatusEnum::TSTAT_SENT)
		.value("DELIVERED", TransmissionStatus::StatusEnum::TSTAT_DELIVERED)
		.value("MAYBE_DELIVERED", TransmissionStatus::StatusEnum::TSTAT_MAYBE_DELIVERED)
		.value("RANGE_RECEIVED", TransmissionStatus::StatusEnum::TSTAT_RANGE_RECEIVED)
		.value("INPUT_FAILURE", TransmissionStatus::StatusEnum::TSTAT_INPUT_FAILURE)
		.value("TEMPORARY_FAILURE", TransmissionStatus::StatusEnum::TSTAT_TEMPORARY_FAILURE)
		.value("PERMANENT_FAILURE", TransmissionStatus::StatusEnum::TSTAT_PERMANENT_FAILURE)
		.value("INV_ADDR", TransmissionStatus::StatusEnum::TSTAT_INV_ADDR);
}