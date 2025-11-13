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

void pbLoggingControl(py::module &m) {
	auto vLoggingControl = py::class_<LoggingControl, Message>(m, "LoggingControl", "Logging Control");
	vLoggingControl.def(py::init<>());
	vLoggingControl.def("__setstate__", &pbUnpickleMessage<LoggingControl>);
	
	vLoggingControl.def_property("op",
	    [](const LoggingControl &x){return static_cast<LoggingControl::ControlOperationEnum>(x.op);},
	    [](LoggingControl *x, const uint8_t &y){x->op = y;},
	    "");
	
	vLoggingControl.def_property("name",
	    [](const LoggingControl &x){return ascii_to_unicode_safe(x.name);},
	    [](LoggingControl &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);

	py::enum_<LoggingControl::ControlOperationEnum>(vLoggingControl, "ControlOperationEnum", "Control Operation")
		.value("REQUEST_START", LoggingControl::ControlOperationEnum::COP_REQUEST_START)
		.value("STARTED", LoggingControl::ControlOperationEnum::COP_STARTED)
		.value("REQUEST_STOP", LoggingControl::ControlOperationEnum::COP_REQUEST_STOP)
		.value("STOPPED", LoggingControl::ControlOperationEnum::COP_STOPPED)
		.value("REQUEST_CURRENT_NAME", LoggingControl::ControlOperationEnum::COP_REQUEST_CURRENT_NAME)
		.value("CURRENT_NAME", LoggingControl::ControlOperationEnum::COP_CURRENT_NAME);
}