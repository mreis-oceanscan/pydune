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

void pbTakeoff(py::module &m) {
	auto vTakeoff = py::class_<Takeoff, Maneuver>(m, "Takeoff", "Takeoff Maneuver");
	vTakeoff.def(py::init<>());
	vTakeoff.def("__setstate__", &pbUnpickleMessage<Takeoff>);
	vTakeoff.def_readwrite("lat", &Takeoff::lat);
	vTakeoff.def_readwrite("lon", &Takeoff::lon);
	vTakeoff.def_readwrite("z", &Takeoff::z);
	
	vTakeoff.def_property("z_units",
	    [](const Takeoff &x){return static_cast<ZUnits>(x.z_units);},
	    [](Takeoff *x, const uint8_t &y){x->z_units = y;},
	    "");
	vTakeoff.def_readwrite("speed", &Takeoff::speed);
	
	vTakeoff.def_property("speed_units",
	    [](const Takeoff &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Takeoff *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vTakeoff.def_readwrite("takeoff_pitch", &Takeoff::takeoff_pitch);
	
	vTakeoff.def_property("custom",
	    [](const Takeoff &x){return ascii_to_unicode_safe(x.custom);},
	    [](Takeoff &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}