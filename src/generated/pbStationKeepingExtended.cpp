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

void pbStationKeepingExtended(py::module &m) {
	auto vStationKeepingExtended = py::class_<StationKeepingExtended, Maneuver>(m, "StationKeepingExtended", "Station Keeping Extended");
	vStationKeepingExtended.def(py::init<>());
	vStationKeepingExtended.def("__setstate__", &pbUnpickleMessage<StationKeepingExtended>);
	vStationKeepingExtended.def_readwrite("lat", &StationKeepingExtended::lat);
	vStationKeepingExtended.def_readwrite("lon", &StationKeepingExtended::lon);
	vStationKeepingExtended.def_readwrite("z", &StationKeepingExtended::z);
	
	vStationKeepingExtended.def_property("z_units",
	    [](const StationKeepingExtended &x){return static_cast<ZUnits>(x.z_units);},
	    [](StationKeepingExtended *x, const uint8_t &y){x->z_units = y;},
	    "");
	vStationKeepingExtended.def_readwrite("radius", &StationKeepingExtended::radius);
	vStationKeepingExtended.def_readwrite("duration", &StationKeepingExtended::duration);
	vStationKeepingExtended.def_readwrite("speed", &StationKeepingExtended::speed);
	
	vStationKeepingExtended.def_property("speed_units",
	    [](const StationKeepingExtended &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](StationKeepingExtended *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vStationKeepingExtended.def_readwrite("popup_period", &StationKeepingExtended::popup_period);
	vStationKeepingExtended.def_readwrite("popup_duration", &StationKeepingExtended::popup_duration);
	vStationKeepingExtended.def_readwrite("flags", &StationKeepingExtended::flags);
	
	vStationKeepingExtended.def_property("custom",
	    [](const StationKeepingExtended &x){return ascii_to_unicode_safe(x.custom);},
	    [](StationKeepingExtended &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<StationKeepingExtended::FlagsBits>(vStationKeepingExtended, "FlagsBits", "Flags", py::arithmetic())
		.value("KEEP_SAFE", StationKeepingExtended::FlagsBits::FLG_KEEP_SAFE);
}