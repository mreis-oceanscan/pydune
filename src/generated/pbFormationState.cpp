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

void pbFormationState(py::module &m) {
	auto vFormationState = py::class_<FormationState, Message>(m, "FormationState", "Formation Tracking State");
	vFormationState.def(py::init<>());
	vFormationState.def("__setstate__", &pbUnpickleMessage<FormationState>);
	
	vFormationState.def_property("type",
	    [](const FormationState &x){return static_cast<FormationState::TypeEnum>(x.type);},
	    [](FormationState *x, const uint8_t &y){x->type = y;},
	    "");
	
	vFormationState.def_property("op",
	    [](const FormationState &x){return static_cast<FormationState::OperationEnum>(x.op);},
	    [](FormationState *x, const uint8_t &y){x->op = y;},
	    "");
	vFormationState.def_readwrite("possimerr", &FormationState::possimerr);
	vFormationState.def_readwrite("converg", &FormationState::converg);
	vFormationState.def_readwrite("turbulence", &FormationState::turbulence);
	
	vFormationState.def_property("possimmon",
	    [](const FormationState &x){return static_cast<FormationState::PositionMismatchMonitorEnum>(x.possimmon);},
	    [](FormationState *x, const uint8_t &y){x->possimmon = y;},
	    "");
	
	vFormationState.def_property("commmon",
	    [](const FormationState &x){return static_cast<FormationState::CommunicationsMonitorEnum>(x.commmon);},
	    [](FormationState *x, const uint8_t &y){x->commmon = y;},
	    "");
	
	vFormationState.def_property("convergmon",
	    [](const FormationState &x){return static_cast<FormationState::ConvergenceEnum>(x.convergmon);},
	    [](FormationState *x, const uint8_t &y){x->convergmon = y;},
	    "");

	py::enum_<FormationState::TypeEnum>(vFormationState, "TypeEnum", "Type")
		.value("REQUEST", FormationState::TypeEnum::FC_REQUEST)
		.value("REPORT", FormationState::TypeEnum::FC_REPORT);

	py::enum_<FormationState::OperationEnum>(vFormationState, "OperationEnum", "Operation")
		.value("START", FormationState::OperationEnum::OP_START)
		.value("STOP", FormationState::OperationEnum::OP_STOP);

	py::enum_<FormationState::PositionMismatchMonitorEnum>(vFormationState, "PositionMismatchMonitorEnum", "Position Mismatch Monitor")
		.value("OK", FormationState::PositionMismatchMonitorEnum::POS_OK)
		.value("WRN", FormationState::PositionMismatchMonitorEnum::POS_WRN)
		.value("LIM", FormationState::PositionMismatchMonitorEnum::POS_LIM);

	py::enum_<FormationState::CommunicationsMonitorEnum>(vFormationState, "CommunicationsMonitorEnum", "Communications Monitor")
		.value("OK", FormationState::CommunicationsMonitorEnum::COMMS_OK)
		.value("TIMEOUT", FormationState::CommunicationsMonitorEnum::COMMS_TIMEOUT);

	py::enum_<FormationState::ConvergenceEnum>(vFormationState, "ConvergenceEnum", "Convergence")
		.value("OK", FormationState::ConvergenceEnum::CONV_OK)
		.value("TIMEOUT", FormationState::ConvergenceEnum::CONV_TIMEOUT);
}