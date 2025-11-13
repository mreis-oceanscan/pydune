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

void pbPlanVariable(py::module &m) {
	auto vPlanVariable = py::class_<PlanVariable, Message>(m, "PlanVariable", "Plan Variable");
	vPlanVariable.def(py::init<>());
	vPlanVariable.def("__setstate__", &pbUnpickleMessage<PlanVariable>);
	
	vPlanVariable.def_property("name",
	    [](const PlanVariable &x){return ascii_to_unicode_safe(x.name);},
	    [](PlanVariable &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vPlanVariable.def_property("value",
	    [](const PlanVariable &x){return ascii_to_unicode_safe(x.value);},
	    [](PlanVariable &x, std::string &s){x.value = s;}, py::return_value_policy::take_ownership);
	
	vPlanVariable.def_property("type",
	    [](const PlanVariable &x){return static_cast<PlanVariable::TypeEnum>(x.type);},
	    [](PlanVariable *x, const uint8_t &y){x->type = y;},
	    "");
	
	vPlanVariable.def_property("access",
	    [](const PlanVariable &x){return static_cast<PlanVariable::AccessTypeEnum>(x.access);},
	    [](PlanVariable *x, const uint8_t &y){x->access = y;},
	    "");

	py::enum_<PlanVariable::TypeEnum>(vPlanVariable, "TypeEnum", "Type")
		.value("BOOLEAN", PlanVariable::TypeEnum::PVT_BOOLEAN)
		.value("NUMBER", PlanVariable::TypeEnum::PVT_NUMBER)
		.value("TEXT", PlanVariable::TypeEnum::PVT_TEXT)
		.value("MESSAGE", PlanVariable::TypeEnum::PVT_MESSAGE);

	py::enum_<PlanVariable::AccessTypeEnum>(vPlanVariable, "AccessTypeEnum", "Access Type")
		.value("INPUT", PlanVariable::AccessTypeEnum::PVA_INPUT)
		.value("OUTPUT", PlanVariable::AccessTypeEnum::PVA_OUTPUT)
		.value("LOCAL", PlanVariable::AccessTypeEnum::PVA_LOCAL);
}