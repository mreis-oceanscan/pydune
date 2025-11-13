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

void pbPWM(py::module &m) {
	auto vPWM = py::class_<PWM, Message>(m, "PWM", "PWM");
	vPWM.def(py::init<>());
	vPWM.def("__setstate__", &pbUnpickleMessage<PWM>);
	vPWM.def_readwrite("id", &PWM::id);
	vPWM.def_readwrite("period", &PWM::period);
	vPWM.def_readwrite("duty_cycle", &PWM::duty_cycle);
}