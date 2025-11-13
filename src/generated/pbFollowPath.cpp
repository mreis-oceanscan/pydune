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

void pbFollowPath(py::module &m) {
	auto vFollowPath = py::class_<FollowPath, Maneuver>(m, "FollowPath", "Follow Path Maneuver");
	vFollowPath.def(py::init<>());
	vFollowPath.def("__setstate__", &pbUnpickleMessage<FollowPath>);
	vFollowPath.def_readwrite("timeout", &FollowPath::timeout);
	vFollowPath.def_readwrite("lat", &FollowPath::lat);
	vFollowPath.def_readwrite("lon", &FollowPath::lon);
	vFollowPath.def_readwrite("z", &FollowPath::z);
	
	vFollowPath.def_property("z_units",
	    [](const FollowPath &x){return static_cast<ZUnits>(x.z_units);},
	    [](FollowPath *x, const uint8_t &y){x->z_units = y;},
	    "");
	vFollowPath.def_readwrite("speed", &FollowPath::speed);
	
	vFollowPath.def_property("speed_units",
	    [](const FollowPath &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](FollowPath *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vFollowPath.def_readwrite("points", &FollowPath::points);
	
	vFollowPath.def_property("custom",
	    [](const FollowPath &x){return ascii_to_unicode_safe(x.custom);},
	    [](FollowPath &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}