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

void pbFormState(py::module &m) {
	auto vFormState = py::class_<FormState, Message>(m, "FormState", "Formation Tracking State");
	vFormState.def(py::init<>());
	vFormState.def("__setstate__", &pbUnpickleMessage<FormState>);
	vFormState.def_readwrite("possimerr", &FormState::possimerr);
	vFormState.def_readwrite("converg", &FormState::converg);
	vFormState.def_readwrite("turbulence", &FormState::turbulence);
	
	vFormState.def_property("possimmon",
	    [](const FormState &x){return static_cast<FormState::PositionMismatchMonitorEnum>(x.possimmon);},
	    [](FormState *x, const uint8_t &y){x->possimmon = y;},
	    "");
	
	vFormState.def_property("commmon",
	    [](const FormState &x){return static_cast<FormState::CommunicationsMonitorEnum>(x.commmon);},
	    [](FormState *x, const uint8_t &y){x->commmon = y;},
	    "");
	
	vFormState.def_property("convergmon",
	    [](const FormState &x){return static_cast<FormState::ConvergenceEnum>(x.convergmon);},
	    [](FormState *x, const uint8_t &y){x->convergmon = y;},
	    "");

	py::enum_<FormState::PositionMismatchMonitorEnum>(vFormState, "PositionMismatchMonitorEnum", "Position Mismatch Monitor")
		.value("OK", FormState::PositionMismatchMonitorEnum::POS_OK)
		.value("WRN", FormState::PositionMismatchMonitorEnum::POS_WRN)
		.value("LIM", FormState::PositionMismatchMonitorEnum::POS_LIM);

	py::enum_<FormState::CommunicationsMonitorEnum>(vFormState, "CommunicationsMonitorEnum", "Communications Monitor")
		.value("OK", FormState::CommunicationsMonitorEnum::COMMS_OK)
		.value("TIMEOUT", FormState::CommunicationsMonitorEnum::COMMS_TIMEOUT);

	py::enum_<FormState::ConvergenceEnum>(vFormState, "ConvergenceEnum", "Convergence")
		.value("OK", FormState::ConvergenceEnum::CONV_OK)
		.value("TIMEOUT", FormState::ConvergenceEnum::CONV_TIMEOUT);
}