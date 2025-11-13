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

void pbPowerChannelControl(py::module &m) {
	auto vPowerChannelControl = py::class_<PowerChannelControl, Message>(m, "PowerChannelControl", "Power Channel Control");
	vPowerChannelControl.def(py::init<>());
	vPowerChannelControl.def("__setstate__", &pbUnpickleMessage<PowerChannelControl>);
	
	vPowerChannelControl.def_property("name",
	    [](const PowerChannelControl &x){return ascii_to_unicode_safe(x.name);},
	    [](PowerChannelControl &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vPowerChannelControl.def_property("op",
	    [](const PowerChannelControl &x){return static_cast<PowerChannelControl::OperationEnum>(x.op);},
	    [](PowerChannelControl *x, const uint8_t &y){x->op = y;},
	    "");
	vPowerChannelControl.def_readwrite("sched_time", &PowerChannelControl::sched_time);

	py::enum_<PowerChannelControl::OperationEnum>(vPowerChannelControl, "OperationEnum", "Operation")
		.value("TURN_OFF", PowerChannelControl::OperationEnum::PCC_OP_TURN_OFF)
		.value("TURN_ON", PowerChannelControl::OperationEnum::PCC_OP_TURN_ON)
		.value("TOGGLE", PowerChannelControl::OperationEnum::PCC_OP_TOGGLE)
		.value("SCHED_ON", PowerChannelControl::OperationEnum::PCC_OP_SCHED_ON)
		.value("SCHED_OFF", PowerChannelControl::OperationEnum::PCC_OP_SCHED_OFF)
		.value("SCHED_RESET", PowerChannelControl::OperationEnum::PCC_OP_SCHED_RESET)
		.value("SAVE", PowerChannelControl::OperationEnum::PCC_OP_SAVE)
		.value("RESTART", PowerChannelControl::OperationEnum::PCC_OP_RESTART);
}