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

void pbSonarPulse(py::module &m) {
	auto vSonarPulse = py::class_<SonarPulse, Message>(m, "SonarPulse", "Sonar Pulse");
	vSonarPulse.def(py::init<>());
	vSonarPulse.def("__setstate__", &pbUnpickleMessage<SonarPulse>);
	vSonarPulse.def_readwrite("frequency", &SonarPulse::frequency);
	vSonarPulse.def_readwrite("pulse_length", &SonarPulse::pulse_length);
	vSonarPulse.def_readwrite("time_delay", &SonarPulse::time_delay);
	vSonarPulse.def_readwrite("simulated_speed", &SonarPulse::simulated_speed);
}