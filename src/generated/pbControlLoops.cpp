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

void pbControlLoops(py::module &m) {
	auto vControlLoops = py::class_<ControlLoops, Message>(m, "ControlLoops", "Control Loops");
	vControlLoops.def(py::init<>());
	vControlLoops.def("__setstate__", &pbUnpickleMessage<ControlLoops>);
	
	vControlLoops.def_property("enable",
	    [](const ControlLoops &x){return static_cast<ControlLoops::EnableEnum>(x.enable);},
	    [](ControlLoops *x, const uint8_t &y){x->enable = y;},
	    "");
	vControlLoops.def_readwrite("mask", &ControlLoops::mask);
	vControlLoops.def_readwrite("scope_ref", &ControlLoops::scope_ref);

	py::enum_<ControlLoops::EnableEnum>(vControlLoops, "EnableEnum", "Enable")
		.value("DISABLE", ControlLoops::EnableEnum::CL_DISABLE)
		.value("ENABLE", ControlLoops::EnableEnum::CL_ENABLE);
}