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

void pbFormCtrlParam(py::module &m) {
	auto vFormCtrlParam = py::class_<FormCtrlParam, Message>(m, "FormCtrlParam", "Formation Control Parameters");
	vFormCtrlParam.def(py::init<>());
	vFormCtrlParam.def("__setstate__", &pbUnpickleMessage<FormCtrlParam>);
	
	vFormCtrlParam.def_property("action",
	    [](const FormCtrlParam &x){return static_cast<FormCtrlParam::ActionEnum>(x.action);},
	    [](FormCtrlParam *x, const uint8_t &y){x->action = y;},
	    "");
	vFormCtrlParam.def_readwrite("longain", &FormCtrlParam::longain);
	vFormCtrlParam.def_readwrite("latgain", &FormCtrlParam::latgain);
	vFormCtrlParam.def_readwrite("bondthick", &FormCtrlParam::bondthick);
	vFormCtrlParam.def_readwrite("leadgain", &FormCtrlParam::leadgain);
	vFormCtrlParam.def_readwrite("deconflgain", &FormCtrlParam::deconflgain);

	py::enum_<FormCtrlParam::ActionEnum>(vFormCtrlParam, "ActionEnum", "Action")
		.value("REQ", FormCtrlParam::ActionEnum::OP_REQ)
		.value("SET", FormCtrlParam::ActionEnum::OP_SET)
		.value("REP", FormCtrlParam::ActionEnum::OP_REP);
}