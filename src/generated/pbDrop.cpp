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

void pbDrop(py::module &m) {
	auto vDrop = py::class_<Drop, Maneuver>(m, "Drop", "Drop Maneuver");
	vDrop.def(py::init<>());
	vDrop.def("__setstate__", &pbUnpickleMessage<Drop>);
	vDrop.def_readwrite("timeout", &Drop::timeout);
	vDrop.def_readwrite("lat", &Drop::lat);
	vDrop.def_readwrite("lon", &Drop::lon);
	vDrop.def_readwrite("z", &Drop::z);
	
	vDrop.def_property("z_units",
	    [](const Drop &x){return static_cast<ZUnits>(x.z_units);},
	    [](Drop *x, const uint8_t &y){x->z_units = y;},
	    "");
	vDrop.def_readwrite("speed", &Drop::speed);
	
	vDrop.def_property("speed_units",
	    [](const Drop &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Drop *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vDrop.def_property("custom",
	    [](const Drop &x){return ascii_to_unicode_safe(x.custom);},
	    [](Drop &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}