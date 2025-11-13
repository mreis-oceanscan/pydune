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

void pbSessionStatus(py::module &m) {
	auto vSessionStatus = py::class_<SessionStatus, Message>(m, "SessionStatus", "Session Status");
	vSessionStatus.def(py::init<>());
	vSessionStatus.def("__setstate__", &pbUnpickleMessage<SessionStatus>);
	vSessionStatus.def_readwrite("sessid", &SessionStatus::sessid);
	
	vSessionStatus.def_property("status",
	    [](const SessionStatus &x){return static_cast<SessionStatus::StatusEnum>(x.status);},
	    [](SessionStatus *x, const uint8_t &y){x->status = y;},
	    "");

	py::enum_<SessionStatus::StatusEnum>(vSessionStatus, "StatusEnum", "Status")
		.value("ESTABLISHED", SessionStatus::StatusEnum::STATUS_ESTABLISHED)
		.value("CLOSED", SessionStatus::StatusEnum::STATUS_CLOSED);
}