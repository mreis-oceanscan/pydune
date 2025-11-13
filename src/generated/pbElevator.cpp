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

void pbElevator(py::module &m) {
	auto vElevator = py::class_<Elevator, Maneuver>(m, "Elevator", "Elevator Maneuver");
	vElevator.def(py::init<>());
	vElevator.def("__setstate__", &pbUnpickleMessage<Elevator>);
	vElevator.def_readwrite("timeout", &Elevator::timeout);
	vElevator.def_readwrite("flags", &Elevator::flags);
	vElevator.def_readwrite("lat", &Elevator::lat);
	vElevator.def_readwrite("lon", &Elevator::lon);
	vElevator.def_readwrite("start_z", &Elevator::start_z);
	
	vElevator.def_property("start_z_units",
	    [](const Elevator &x){return static_cast<ZUnits>(x.start_z_units);},
	    [](Elevator *x, const uint8_t &y){x->start_z_units = y;},
	    "");
	vElevator.def_readwrite("end_z", &Elevator::end_z);
	
	vElevator.def_property("end_z_units",
	    [](const Elevator &x){return static_cast<ZUnits>(x.end_z_units);},
	    [](Elevator *x, const uint8_t &y){x->end_z_units = y;},
	    "");
	vElevator.def_readwrite("radius", &Elevator::radius);
	vElevator.def_readwrite("speed", &Elevator::speed);
	
	vElevator.def_property("speed_units",
	    [](const Elevator &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Elevator *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vElevator.def_property("custom",
	    [](const Elevator &x){return ascii_to_unicode_safe(x.custom);},
	    [](Elevator &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<Elevator::FlagsBits>(vElevator, "FlagsBits", "Flags", py::arithmetic())
		.value("CURR_POS", Elevator::FlagsBits::FLG_CURR_POS);
}