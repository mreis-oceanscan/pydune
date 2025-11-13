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

void pbLaunch(py::module &m) {
	auto vLaunch = py::class_<Launch, Maneuver>(m, "Launch", "Launch Maneuver");
	vLaunch.def(py::init<>());
	vLaunch.def("__setstate__", &pbUnpickleMessage<Launch>);
	vLaunch.def_readwrite("timeout", &Launch::timeout);
	vLaunch.def_readwrite("lat", &Launch::lat);
	vLaunch.def_readwrite("lon", &Launch::lon);
	vLaunch.def_readwrite("z", &Launch::z);
	
	vLaunch.def_property("z_units",
	    [](const Launch &x){return static_cast<ZUnits>(x.z_units);},
	    [](Launch *x, const uint8_t &y){x->z_units = y;},
	    "");
	vLaunch.def_readwrite("speed", &Launch::speed);
	
	vLaunch.def_property("speed_units",
	    [](const Launch &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Launch *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vLaunch.def_property("custom",
	    [](const Launch &x){return ascii_to_unicode_safe(x.custom);},
	    [](Launch &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}