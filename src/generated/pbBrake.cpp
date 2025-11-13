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

void pbBrake(py::module &m) {
	auto vBrake = py::class_<Brake, Message>(m, "Brake", "Brake");
	vBrake.def(py::init<>());
	vBrake.def("__setstate__", &pbUnpickleMessage<Brake>);
	
	vBrake.def_property("op",
	    [](const Brake &x){return static_cast<Brake::OperationEnum>(x.op);},
	    [](Brake *x, const uint8_t &y){x->op = y;},
	    "");

	py::enum_<Brake::OperationEnum>(vBrake, "OperationEnum", "Operation")
		.value("STOP", Brake::OperationEnum::OP_STOP)
		.value("START", Brake::OperationEnum::OP_START)
		.value("REVERT", Brake::OperationEnum::OP_REVERT);
}