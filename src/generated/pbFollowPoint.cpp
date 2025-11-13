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

void pbFollowPoint(py::module &m) {
	auto vFollowPoint = py::class_<FollowPoint, Maneuver>(m, "FollowPoint", "Follow Point Maneuver");
	vFollowPoint.def(py::init<>());
	vFollowPoint.def("__setstate__", &pbUnpickleMessage<FollowPoint>);
	
	vFollowPoint.def_property("target",
	    [](const FollowPoint &x){return ascii_to_unicode_safe(x.target);},
	    [](FollowPoint &x, std::string &s){x.target = s;}, py::return_value_policy::take_ownership);
	vFollowPoint.def_readwrite("max_speed", &FollowPoint::max_speed);
	
	vFollowPoint.def_property("speed_units",
	    [](const FollowPoint &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](FollowPoint *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vFollowPoint.def_readwrite("lat", &FollowPoint::lat);
	vFollowPoint.def_readwrite("lon", &FollowPoint::lon);
	vFollowPoint.def_readwrite("z", &FollowPoint::z);
	
	vFollowPoint.def_property("z_units",
	    [](const FollowPoint &x){return static_cast<ZUnits>(x.z_units);},
	    [](FollowPoint *x, const uint8_t &y){x->z_units = y;},
	    "");
	
	vFollowPoint.def_property("custom",
	    [](const FollowPoint &x){return ascii_to_unicode_safe(x.custom);},
	    [](FollowPoint &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}