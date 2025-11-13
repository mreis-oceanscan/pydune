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

void pbFollowTrajectory(py::module &m) {
	auto vFollowTrajectory = py::class_<FollowTrajectory, Maneuver>(m, "FollowTrajectory", "Follow Trajectory");
	vFollowTrajectory.def(py::init<>());
	vFollowTrajectory.def("__setstate__", &pbUnpickleMessage<FollowTrajectory>);
	vFollowTrajectory.def_readwrite("timeout", &FollowTrajectory::timeout);
	vFollowTrajectory.def_readwrite("lat", &FollowTrajectory::lat);
	vFollowTrajectory.def_readwrite("lon", &FollowTrajectory::lon);
	vFollowTrajectory.def_readwrite("z", &FollowTrajectory::z);
	
	vFollowTrajectory.def_property("z_units",
	    [](const FollowTrajectory &x){return static_cast<ZUnits>(x.z_units);},
	    [](FollowTrajectory *x, const uint8_t &y){x->z_units = y;},
	    "");
	vFollowTrajectory.def_readwrite("speed", &FollowTrajectory::speed);
	
	vFollowTrajectory.def_property("speed_units",
	    [](const FollowTrajectory &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](FollowTrajectory *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vFollowTrajectory.def_readwrite("points", &FollowTrajectory::points);
	
	vFollowTrajectory.def_property("custom",
	    [](const FollowTrajectory &x){return ascii_to_unicode_safe(x.custom);},
	    [](FollowTrajectory &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}