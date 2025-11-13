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

void pbPlanGeneration(py::module &m) {
	auto vPlanGeneration = py::class_<PlanGeneration, Message>(m, "PlanGeneration", "Plan Generation");
	vPlanGeneration.def(py::init<>());
	vPlanGeneration.def("__setstate__", &pbUnpickleMessage<PlanGeneration>);
	
	vPlanGeneration.def_property("cmd",
	    [](const PlanGeneration &x){return static_cast<PlanGeneration::CommandEnum>(x.cmd);},
	    [](PlanGeneration *x, const uint8_t &y){x->cmd = y;},
	    "");
	
	vPlanGeneration.def_property("op",
	    [](const PlanGeneration &x){return static_cast<PlanGeneration::OperationEnum>(x.op);},
	    [](PlanGeneration *x, const uint8_t &y){x->op = y;},
	    "");
	
	vPlanGeneration.def_property("plan_id",
	    [](const PlanGeneration &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanGeneration &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	
	vPlanGeneration.def_property("params",
	    [](const PlanGeneration &x){return ascii_to_unicode_safe(x.params);},
	    [](PlanGeneration &x, std::string &s){x.params = s;}, py::return_value_policy::take_ownership);

	py::enum_<PlanGeneration::CommandEnum>(vPlanGeneration, "CommandEnum", "Command")
		.value("GENERATE", PlanGeneration::CommandEnum::CMD_GENERATE)
		.value("EXECUTE", PlanGeneration::CommandEnum::CMD_EXECUTE);

	py::enum_<PlanGeneration::OperationEnum>(vPlanGeneration, "OperationEnum", "Operation")
		.value("REQUEST", PlanGeneration::OperationEnum::OP_REQUEST)
		.value("ERROR", PlanGeneration::OperationEnum::OP_ERROR)
		.value("SUCCESS", PlanGeneration::OperationEnum::OP_SUCCESS);
}