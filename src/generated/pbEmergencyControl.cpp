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

void pbEmergencyControl(py::module &m) {
	auto vEmergencyControl = py::class_<EmergencyControl, Message>(m, "EmergencyControl", "Emergency Control");
	vEmergencyControl.def(py::init<>());
	vEmergencyControl.def("__setstate__", &pbUnpickleMessage<EmergencyControl>);
	
	vEmergencyControl.def_property("command",
	    [](const EmergencyControl &x){return static_cast<EmergencyControl::CommandEnum>(x.command);},
	    [](EmergencyControl *x, const uint8_t &y){x->command = y;},
	    "");
	
	vEmergencyControl.def_property("plan",
	[](const EmergencyControl &x){return x.plan.isNull() ? nullptr : x.plan.get();},
	[](EmergencyControl *x, const py::handle &y){
	    if(y.is_none()){
	        x->plan.clear();
	    } else {
	        try {
	            x->plan.set(y.cast<PlanSpecification*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are PlanSpecification or NoneType.");
	        }
	        x->plan.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<EmergencyControl::CommandEnum>(vEmergencyControl, "CommandEnum", "Command")
		.value("ENABLE", EmergencyControl::CommandEnum::ECTL_ENABLE)
		.value("DISABLE", EmergencyControl::CommandEnum::ECTL_DISABLE)
		.value("START", EmergencyControl::CommandEnum::ECTL_START)
		.value("STOP", EmergencyControl::CommandEnum::ECTL_STOP)
		.value("QUERY", EmergencyControl::CommandEnum::ECTL_QUERY)
		.value("SET_PLAN", EmergencyControl::CommandEnum::ECTL_SET_PLAN);
}