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

void pbCommsRelay(py::module &m) {
	auto vCommsRelay = py::class_<CommsRelay, Maneuver>(m, "CommsRelay", "Communications Relay");
	vCommsRelay.def(py::init<>());
	vCommsRelay.def("__setstate__", &pbUnpickleMessage<CommsRelay>);
	vCommsRelay.def_readwrite("lat", &CommsRelay::lat);
	vCommsRelay.def_readwrite("lon", &CommsRelay::lon);
	vCommsRelay.def_readwrite("speed", &CommsRelay::speed);
	
	vCommsRelay.def_property("speed_units",
	    [](const CommsRelay &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](CommsRelay *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vCommsRelay.def_readwrite("duration", &CommsRelay::duration);
	vCommsRelay.def_readwrite("sys_a", &CommsRelay::sys_a);
	vCommsRelay.def_readwrite("sys_b", &CommsRelay::sys_b);
	vCommsRelay.def_readwrite("move_threshold", &CommsRelay::move_threshold);
}