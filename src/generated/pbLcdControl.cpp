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

void pbLcdControl(py::module &m) {
	auto vLcdControl = py::class_<LcdControl, Message>(m, "LcdControl", "LCD Control");
	vLcdControl.def(py::init<>());
	vLcdControl.def("__setstate__", &pbUnpickleMessage<LcdControl>);
	
	vLcdControl.def_property("op",
	    [](const LcdControl &x){return static_cast<LcdControl::OperationEnum>(x.op);},
	    [](LcdControl *x, const uint8_t &y){x->op = y;},
	    "");
	
	vLcdControl.def_property("text",
	    [](const LcdControl &x){return ascii_to_unicode_safe(x.text);},
	    [](LcdControl &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);

	py::enum_<LcdControl::OperationEnum>(vLcdControl, "OperationEnum", "Operation")
		.value("TURN_OFF", LcdControl::OperationEnum::OP_TURN_OFF)
		.value("TURN_ON", LcdControl::OperationEnum::OP_TURN_ON)
		.value("CLEAR", LcdControl::OperationEnum::OP_CLEAR)
		.value("WRITE0", LcdControl::OperationEnum::OP_WRITE0)
		.value("WRITE1", LcdControl::OperationEnum::OP_WRITE1);
}