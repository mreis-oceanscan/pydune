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

void pbVehicleCommand(py::module &m) {
	auto vVehicleCommand = py::class_<VehicleCommand, Message>(m, "VehicleCommand", "Vehicle Command");
	vVehicleCommand.def(py::init<>());
	vVehicleCommand.def("__setstate__", &pbUnpickleMessage<VehicleCommand>);
	
	vVehicleCommand.def_property("type",
	    [](const VehicleCommand &x){return static_cast<VehicleCommand::TypeEnum>(x.type);},
	    [](VehicleCommand *x, const uint8_t &y){x->type = y;},
	    "");
	vVehicleCommand.def_readwrite("request_id", &VehicleCommand::request_id);
	
	vVehicleCommand.def_property("command",
	    [](const VehicleCommand &x){return static_cast<VehicleCommand::CommandEnum>(x.command);},
	    [](VehicleCommand *x, const uint8_t &y){x->command = y;},
	    "");
	
	vVehicleCommand.def_property("maneuver",
	[](const VehicleCommand &x){return x.maneuver.isNull() ? nullptr : x.maneuver.get();},
	[](VehicleCommand *x, const py::handle &y){
	    if(y.is_none()){
	        x->maneuver.clear();
	    } else {
	        try {
	            x->maneuver.set(y.cast<Maneuver*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Maneuver or NoneType.");
	        }
	        x->maneuver.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	vVehicleCommand.def_readwrite("calib_time", &VehicleCommand::calib_time);
	
	vVehicleCommand.def_property("info",
	    [](const VehicleCommand &x){return ascii_to_unicode_safe(x.info);},
	    [](VehicleCommand &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<VehicleCommand::TypeEnum>(vVehicleCommand, "TypeEnum", "Type")
		.value("REQUEST", VehicleCommand::TypeEnum::VC_REQUEST)
		.value("SUCCESS", VehicleCommand::TypeEnum::VC_SUCCESS)
		.value("IN_PROGRESS", VehicleCommand::TypeEnum::VC_IN_PROGRESS)
		.value("FAILURE", VehicleCommand::TypeEnum::VC_FAILURE);

	py::enum_<VehicleCommand::CommandEnum>(vVehicleCommand, "CommandEnum", "Command")
		.value("EXEC_MANEUVER", VehicleCommand::CommandEnum::VC_EXEC_MANEUVER)
		.value("STOP_MANEUVER", VehicleCommand::CommandEnum::VC_STOP_MANEUVER)
		.value("START_CALIBRATION", VehicleCommand::CommandEnum::VC_START_CALIBRATION)
		.value("STOP_CALIBRATION", VehicleCommand::CommandEnum::VC_STOP_CALIBRATION);
}