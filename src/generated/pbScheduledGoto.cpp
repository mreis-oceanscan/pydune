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

void pbScheduledGoto(py::module &m) {
	auto vScheduledGoto = py::class_<ScheduledGoto, Maneuver>(m, "ScheduledGoto", "Scheduled Goto");
	vScheduledGoto.def(py::init<>());
	vScheduledGoto.def("__setstate__", &pbUnpickleMessage<ScheduledGoto>);
	vScheduledGoto.def_readwrite("arrival_time", &ScheduledGoto::arrival_time);
	vScheduledGoto.def_readwrite("lat", &ScheduledGoto::lat);
	vScheduledGoto.def_readwrite("lon", &ScheduledGoto::lon);
	vScheduledGoto.def_readwrite("z", &ScheduledGoto::z);
	
	vScheduledGoto.def_property("z_units",
	    [](const ScheduledGoto &x){return static_cast<ZUnits>(x.z_units);},
	    [](ScheduledGoto *x, const uint8_t &y){x->z_units = y;},
	    "");
	vScheduledGoto.def_readwrite("travel_z", &ScheduledGoto::travel_z);
	
	vScheduledGoto.def_property("travel_z_units",
	    [](const ScheduledGoto &x){return static_cast<ZUnits>(x.travel_z_units);},
	    [](ScheduledGoto *x, const uint8_t &y){x->travel_z_units = y;},
	    "");
	
	vScheduledGoto.def_property("delayed",
	    [](const ScheduledGoto &x){return static_cast<ScheduledGoto::DelayedBehaviorEnum>(x.delayed);},
	    [](ScheduledGoto *x, const uint8_t &y){x->delayed = y;},
	    "");

	py::enum_<ScheduledGoto::DelayedBehaviorEnum>(vScheduledGoto, "DelayedBehaviorEnum", "Delayed Behavior")
		.value("RESUME", ScheduledGoto::DelayedBehaviorEnum::DBEH_RESUME)
		.value("SKIP", ScheduledGoto::DelayedBehaviorEnum::DBEH_SKIP)
		.value("FAIL", ScheduledGoto::DelayedBehaviorEnum::DBEH_FAIL);
}