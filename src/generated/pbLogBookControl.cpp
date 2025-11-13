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

void pbLogBookControl(py::module &m) {
	auto vLogBookControl = py::class_<LogBookControl, Message>(m, "LogBookControl", "Log Book Control");
	vLogBookControl.def(py::init<>());
	vLogBookControl.def("__setstate__", &pbUnpickleMessage<LogBookControl>);
	
	vLogBookControl.def_property("command",
	    [](const LogBookControl &x){return static_cast<LogBookControl::CommandEnum>(x.command);},
	    [](LogBookControl *x, const uint8_t &y){x->command = y;},
	    "");
	vLogBookControl.def_readwrite("htime", &LogBookControl::htime);
	vLogBookControl.def_readwrite("msg", &LogBookControl::msg);

	py::enum_<LogBookControl::CommandEnum>(vLogBookControl, "CommandEnum", "Command")
		.value("GET", LogBookControl::CommandEnum::LBC_GET)
		.value("CLEAR", LogBookControl::CommandEnum::LBC_CLEAR)
		.value("GET_ERR", LogBookControl::CommandEnum::LBC_GET_ERR)
		.value("REPLY", LogBookControl::CommandEnum::LBC_REPLY);
}