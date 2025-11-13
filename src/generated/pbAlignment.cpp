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

void pbAlignment(py::module &m) {
	auto vAlignment = py::class_<Alignment, Maneuver>(m, "Alignment", "Alignment Maneuver");
	vAlignment.def(py::init<>());
	vAlignment.def("__setstate__", &pbUnpickleMessage<Alignment>);
	vAlignment.def_readwrite("timeout", &Alignment::timeout);
	vAlignment.def_readwrite("lat", &Alignment::lat);
	vAlignment.def_readwrite("lon", &Alignment::lon);
	vAlignment.def_readwrite("speed", &Alignment::speed);
	
	vAlignment.def_property("speed_units",
	    [](const Alignment &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Alignment *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vAlignment.def_property("custom",
	    [](const Alignment &x){return ascii_to_unicode_safe(x.custom);},
	    [](Alignment &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}