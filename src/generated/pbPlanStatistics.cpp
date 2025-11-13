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

void pbPlanStatistics(py::module &m) {
	auto vPlanStatistics = py::class_<PlanStatistics, Message>(m, "PlanStatistics", "Plan Statistics");
	vPlanStatistics.def(py::init<>());
	vPlanStatistics.def("__setstate__", &pbUnpickleMessage<PlanStatistics>);
	
	vPlanStatistics.def_property("plan_id",
	    [](const PlanStatistics &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanStatistics &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	
	vPlanStatistics.def_property("type",
	    [](const PlanStatistics &x){return static_cast<PlanStatistics::TypeEnum>(x.type);},
	    [](PlanStatistics *x, const uint8_t &y){x->type = y;},
	    "");
	vPlanStatistics.def_readwrite("properties", &PlanStatistics::properties);
	
	vPlanStatistics.def_property("durations",
	    [](const PlanStatistics &x){return ascii_to_unicode_safe(x.durations);},
	    [](PlanStatistics &x, std::string &s){x.durations = s;}, py::return_value_policy::take_ownership);
	
	vPlanStatistics.def_property("distances",
	    [](const PlanStatistics &x){return ascii_to_unicode_safe(x.distances);},
	    [](PlanStatistics &x, std::string &s){x.distances = s;}, py::return_value_policy::take_ownership);
	
	vPlanStatistics.def_property("actions",
	    [](const PlanStatistics &x){return ascii_to_unicode_safe(x.actions);},
	    [](PlanStatistics &x, std::string &s){x.actions = s;}, py::return_value_policy::take_ownership);
	
	vPlanStatistics.def_property("fuel",
	    [](const PlanStatistics &x){return ascii_to_unicode_safe(x.fuel);},
	    [](PlanStatistics &x, std::string &s){x.fuel = s;}, py::return_value_policy::take_ownership);

	py::enum_<PlanStatistics::TypeEnum>(vPlanStatistics, "TypeEnum", "Type")
		.value("PREPLAN", PlanStatistics::TypeEnum::TP_PREPLAN)
		.value("INPLAN", PlanStatistics::TypeEnum::TP_INPLAN)
		.value("POSTPLAN", PlanStatistics::TypeEnum::TP_POSTPLAN);

	py::enum_<PlanStatistics::PropertiesBits>(vPlanStatistics, "PropertiesBits", "Properties", py::arithmetic())
		.value("BASIC", PlanStatistics::PropertiesBits::PRP_BASIC)
		.value("NONLINEAR", PlanStatistics::PropertiesBits::PRP_NONLINEAR)
		.value("INFINITE", PlanStatistics::PropertiesBits::PRP_INFINITE)
		.value("CYCLICAL", PlanStatistics::PropertiesBits::PRP_CYCLICAL)
		.value("ALL", PlanStatistics::PropertiesBits::PRP_ALL);
}