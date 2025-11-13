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

void pbSoiCommand(py::module &m) {
	auto vSoiCommand = py::class_<SoiCommand, Message>(m, "SoiCommand", "SOI Command");
	vSoiCommand.def(py::init<>());
	vSoiCommand.def("__setstate__", &pbUnpickleMessage<SoiCommand>);
	
	vSoiCommand.def_property("type",
	    [](const SoiCommand &x){return static_cast<SoiCommand::TypeEnum>(x.type);},
	    [](SoiCommand *x, const uint8_t &y){x->type = y;},
	    "");
	
	vSoiCommand.def_property("command",
	    [](const SoiCommand &x){return static_cast<SoiCommand::CommandEnum>(x.command);},
	    [](SoiCommand *x, const uint8_t &y){x->command = y;},
	    "");
	
	vSoiCommand.def_property("settings",
	    [](const SoiCommand &x){return ascii_to_unicode_safe(x.settings);},
	    [](SoiCommand &x, std::string &s){x.settings = s;}, py::return_value_policy::take_ownership);
	
	vSoiCommand.def_property("plan",
	[](const SoiCommand &x){return x.plan.isNull() ? nullptr : x.plan.get();},
	[](SoiCommand *x, const py::handle &y){
	    if(y.is_none()){
	        x->plan.clear();
	    } else {
	        try {
	            x->plan.set(y.cast<SoiPlan*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are SoiPlan or NoneType.");
	        }
	        x->plan.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vSoiCommand.def_property("info",
	    [](const SoiCommand &x){return ascii_to_unicode_safe(x.info);},
	    [](SoiCommand &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<SoiCommand::TypeEnum>(vSoiCommand, "TypeEnum", "Type")
		.value("REQUEST", SoiCommand::TypeEnum::SOITYPE_REQUEST)
		.value("SUCCESS", SoiCommand::TypeEnum::SOITYPE_SUCCESS)
		.value("ERROR", SoiCommand::TypeEnum::SOITYPE_ERROR);

	py::enum_<SoiCommand::CommandEnum>(vSoiCommand, "CommandEnum", "Command")
		.value("EXEC", SoiCommand::CommandEnum::SOICMD_EXEC)
		.value("STOP", SoiCommand::CommandEnum::SOICMD_STOP)
		.value("SET_PARAMS", SoiCommand::CommandEnum::SOICMD_SET_PARAMS)
		.value("GET_PARAMS", SoiCommand::CommandEnum::SOICMD_GET_PARAMS)
		.value("GET_PLAN", SoiCommand::CommandEnum::SOICMD_GET_PLAN)
		.value("RESUME", SoiCommand::CommandEnum::SOICMD_RESUME);
}