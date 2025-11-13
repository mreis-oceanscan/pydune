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

void pbReplayControl(py::module &m) {
	auto vReplayControl = py::class_<ReplayControl, Message>(m, "ReplayControl", "Replay Control");
	vReplayControl.def(py::init<>());
	vReplayControl.def("__setstate__", &pbUnpickleMessage<ReplayControl>);
	
	vReplayControl.def_property("op",
	    [](const ReplayControl &x){return static_cast<ReplayControl::OperationEnum>(x.op);},
	    [](ReplayControl *x, const uint8_t &y){x->op = y;},
	    "");
	
	vReplayControl.def_property("file",
	    [](const ReplayControl &x){return ascii_to_unicode_safe(x.file);},
	    [](ReplayControl &x, std::string &s){x.file = s;}, py::return_value_policy::take_ownership);

	py::enum_<ReplayControl::OperationEnum>(vReplayControl, "OperationEnum", "Operation")
		.value("START", ReplayControl::OperationEnum::ROP_START)
		.value("STOP", ReplayControl::OperationEnum::ROP_STOP)
		.value("PAUSE", ReplayControl::OperationEnum::ROP_PAUSE)
		.value("RESUME", ReplayControl::OperationEnum::ROP_RESUME);
}