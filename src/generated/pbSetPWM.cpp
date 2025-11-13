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

void pbSetPWM(py::module &m) {
	auto vSetPWM = py::class_<SetPWM, Message>(m, "SetPWM", "Set PWM");
	vSetPWM.def(py::init<>());
	vSetPWM.def("__setstate__", &pbUnpickleMessage<SetPWM>);
	vSetPWM.def_readwrite("id", &SetPWM::id);
	vSetPWM.def_readwrite("period", &SetPWM::period);
	vSetPWM.def_readwrite("duty_cycle", &SetPWM::duty_cycle);
}