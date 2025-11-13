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

void pbLand(py::module &m) {
	auto vLand = py::class_<Land, Maneuver>(m, "Land", "Land Maneuver");
	vLand.def(py::init<>());
	vLand.def("__setstate__", &pbUnpickleMessage<Land>);
	vLand.def_readwrite("lat", &Land::lat);
	vLand.def_readwrite("lon", &Land::lon);
	vLand.def_readwrite("z", &Land::z);
	
	vLand.def_property("z_units",
	    [](const Land &x){return static_cast<ZUnits>(x.z_units);},
	    [](Land *x, const uint8_t &y){x->z_units = y;},
	    "");
	vLand.def_readwrite("speed", &Land::speed);
	
	vLand.def_property("speed_units",
	    [](const Land &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Land *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vLand.def_readwrite("abort_z", &Land::abort_z);
	vLand.def_readwrite("bearing", &Land::bearing);
	vLand.def_readwrite("glide_slope", &Land::glide_slope);
	vLand.def_readwrite("glide_slope_alt", &Land::glide_slope_alt);
	
	vLand.def_property("custom",
	    [](const Land &x){return ascii_to_unicode_safe(x.custom);},
	    [](Land &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}