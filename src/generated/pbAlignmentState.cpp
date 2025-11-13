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

void pbAlignmentState(py::module &m) {
	auto vAlignmentState = py::class_<AlignmentState, Message>(m, "AlignmentState", "Alignment State");
	vAlignmentState.def(py::init<>());
	vAlignmentState.def("__setstate__", &pbUnpickleMessage<AlignmentState>);
	
	vAlignmentState.def_property("state",
	    [](const AlignmentState &x){return static_cast<AlignmentState::StateEnum>(x.state);},
	    [](AlignmentState *x, const uint8_t &y){x->state = y;},
	    "");

	py::enum_<AlignmentState::StateEnum>(vAlignmentState, "StateEnum", "State")
		.value("NOT_ALIGNED", AlignmentState::StateEnum::AS_NOT_ALIGNED)
		.value("ALIGNED", AlignmentState::StateEnum::AS_ALIGNED)
		.value("NOT_SUPPORTED", AlignmentState::StateEnum::AS_NOT_SUPPORTED)
		.value("ALIGNING", AlignmentState::StateEnum::AS_ALIGNING)
		.value("WRONG_MEDIUM", AlignmentState::StateEnum::AS_WRONG_MEDIUM)
		.value("COARSE_ALIGNMENT", AlignmentState::StateEnum::AS_COARSE_ALIGNMENT)
		.value("FINE_ALIGNMENT", AlignmentState::StateEnum::AS_FINE_ALIGNMENT)
		.value("SYSTEM_READY", AlignmentState::StateEnum::AS_SYSTEM_READY);
}