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

void pbLeakSimulation(py::module &m) {
	auto vLeakSimulation = py::class_<LeakSimulation, Message>(m, "LeakSimulation", "Leak Simulation");
	vLeakSimulation.def(py::init<>());
	vLeakSimulation.def("__setstate__", &pbUnpickleMessage<LeakSimulation>);
	
	vLeakSimulation.def_property("op",
	    [](const LeakSimulation &x){return static_cast<LeakSimulation::OperationEnum>(x.op);},
	    [](LeakSimulation *x, const uint8_t &y){x->op = y;},
	    "");
	
	vLeakSimulation.def_property("entities",
	    [](const LeakSimulation &x){return ascii_to_unicode_safe(x.entities);},
	    [](LeakSimulation &x, std::string &s){x.entities = s;}, py::return_value_policy::take_ownership);

	py::enum_<LeakSimulation::OperationEnum>(vLeakSimulation, "OperationEnum", "Operation")
		.value("OFF", LeakSimulation::OperationEnum::LSIM_OFF)
		.value("ON", LeakSimulation::OperationEnum::LSIM_ON);
}