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

void pbStationKeeping(py::module &m) {
	auto vStationKeeping = py::class_<StationKeeping, Maneuver>(m, "StationKeeping", "Station Keeping");
	vStationKeeping.def(py::init<>());
	vStationKeeping.def("__setstate__", &pbUnpickleMessage<StationKeeping>);
	vStationKeeping.def_readwrite("lat", &StationKeeping::lat);
	vStationKeeping.def_readwrite("lon", &StationKeeping::lon);
	vStationKeeping.def_readwrite("z", &StationKeeping::z);
	
	vStationKeeping.def_property("z_units",
	    [](const StationKeeping &x){return static_cast<ZUnits>(x.z_units);},
	    [](StationKeeping *x, const uint8_t &y){x->z_units = y;},
	    "");
	vStationKeeping.def_readwrite("radius", &StationKeeping::radius);
	vStationKeeping.def_readwrite("duration", &StationKeeping::duration);
	vStationKeeping.def_readwrite("speed", &StationKeeping::speed);
	
	vStationKeeping.def_property("speed_units",
	    [](const StationKeeping &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](StationKeeping *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vStationKeeping.def_property("custom",
	    [](const StationKeeping &x){return ascii_to_unicode_safe(x.custom);},
	    [](StationKeeping &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}