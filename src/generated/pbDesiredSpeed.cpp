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

void pbDesiredSpeed(py::module &m) {
	auto vDesiredSpeed = py::class_<DesiredSpeed, ControlCommand>(m, "DesiredSpeed", "Desired Speed");
	vDesiredSpeed.def(py::init<>());
	vDesiredSpeed.def("__setstate__", &pbUnpickleMessage<DesiredSpeed>);
	vDesiredSpeed.def_readwrite("value", &DesiredSpeed::value);
	
	vDesiredSpeed.def_property("speed_units",
	    [](const DesiredSpeed &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](DesiredSpeed *x, const uint8_t &y){x->speed_units = y;},
	    "");
}