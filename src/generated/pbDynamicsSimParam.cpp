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

void pbDynamicsSimParam(py::module &m) {
	auto vDynamicsSimParam = py::class_<DynamicsSimParam, Message>(m, "DynamicsSimParam", "Dynamics Simulation Parameters");
	vDynamicsSimParam.def(py::init<>());
	vDynamicsSimParam.def("__setstate__", &pbUnpickleMessage<DynamicsSimParam>);
	
	vDynamicsSimParam.def_property("op",
	    [](const DynamicsSimParam &x){return static_cast<DynamicsSimParam::ActionontheVehicleSimulationParametersEnum>(x.op);},
	    [](DynamicsSimParam *x, const uint8_t &y){x->op = y;},
	    "");
	vDynamicsSimParam.def_readwrite("tas2acc_pgain", &DynamicsSimParam::tas2acc_pgain);
	vDynamicsSimParam.def_readwrite("bank2p_pgain", &DynamicsSimParam::bank2p_pgain);

	py::enum_<DynamicsSimParam::ActionontheVehicleSimulationParametersEnum>(vDynamicsSimParam, "ActionOnTheVehicleSimulationParametersEnum", "Action on the Vehicle Simulation Parameters")
		.value("REQUEST", DynamicsSimParam::ActionontheVehicleSimulationParametersEnum::OP_REQUEST)
		.value("SET", DynamicsSimParam::ActionontheVehicleSimulationParametersEnum::OP_SET)
		.value("REPORT", DynamicsSimParam::ActionontheVehicleSimulationParametersEnum::OP_REPORT);
}