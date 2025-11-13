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

void pbFollowSystem(py::module &m) {
	auto vFollowSystem = py::class_<FollowSystem, Message>(m, "FollowSystem", "Follow System");
	vFollowSystem.def(py::init<>());
	vFollowSystem.def("__setstate__", &pbUnpickleMessage<FollowSystem>);
	vFollowSystem.def_readwrite("system", &FollowSystem::system);
	vFollowSystem.def_readwrite("duration", &FollowSystem::duration);
	vFollowSystem.def_readwrite("speed", &FollowSystem::speed);
	
	vFollowSystem.def_property("speed_units",
	    [](const FollowSystem &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](FollowSystem *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vFollowSystem.def_readwrite("x", &FollowSystem::x);
	vFollowSystem.def_readwrite("y", &FollowSystem::y);
	vFollowSystem.def_readwrite("z", &FollowSystem::z);
	
	vFollowSystem.def_property("z_units",
	    [](const FollowSystem &x){return static_cast<ZUnits>(x.z_units);},
	    [](FollowSystem *x, const uint8_t &y){x->z_units = y;},
	    "");
}