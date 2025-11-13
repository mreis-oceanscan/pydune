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

void pbUASimulation(py::module &m) {
	auto vUASimulation = py::class_<UASimulation, Message>(m, "UASimulation", "Underwater Acoustics Simulation");
	vUASimulation.def(py::init<>());
	vUASimulation.def("__setstate__", &pbUnpickleMessage<UASimulation>);
	
	vUASimulation.def_property("type",
	    [](const UASimulation &x){return static_cast<UASimulation::TypeEnum>(x.type);},
	    [](UASimulation *x, const uint8_t &y){x->type = y;},
	    "");
	vUASimulation.def_readwrite("speed", &UASimulation::speed);
	
	vUASimulation.def_property("data",
	    [](const UASimulation &x){return py::bytes(x.data.data(), x.data.size());},
	    [](UASimulation &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);

	py::enum_<UASimulation::TypeEnum>(vUASimulation, "TypeEnum", "Type")
		.value("DATA", UASimulation::TypeEnum::UAS_DATA)
		.value("PING", UASimulation::TypeEnum::UAS_PING)
		.value("PING_REPLY", UASimulation::TypeEnum::UAS_PING_REPLY);
}