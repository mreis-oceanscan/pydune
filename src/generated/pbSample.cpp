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

void pbSample(py::module &m) {
	auto vSample = py::class_<Sample, Maneuver>(m, "Sample", "Sample Maneuver");
	vSample.def(py::init<>());
	vSample.def("__setstate__", &pbUnpickleMessage<Sample>);
	vSample.def_readwrite("timeout", &Sample::timeout);
	vSample.def_readwrite("lat", &Sample::lat);
	vSample.def_readwrite("lon", &Sample::lon);
	vSample.def_readwrite("z", &Sample::z);
	
	vSample.def_property("z_units",
	    [](const Sample &x){return static_cast<ZUnits>(x.z_units);},
	    [](Sample *x, const uint8_t &y){x->z_units = y;},
	    "");
	vSample.def_readwrite("speed", &Sample::speed);
	
	vSample.def_property("speed_units",
	    [](const Sample &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Sample *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vSample.def_property("syringe0",
	    [](const Sample &x){return static_cast<Boolean>(x.syringe0);},
	    [](Sample *x, const uint8_t &y){x->syringe0 = y;},
	    "");
	
	vSample.def_property("syringe1",
	    [](const Sample &x){return static_cast<Boolean>(x.syringe1);},
	    [](Sample *x, const uint8_t &y){x->syringe1 = y;},
	    "");
	
	vSample.def_property("syringe2",
	    [](const Sample &x){return static_cast<Boolean>(x.syringe2);},
	    [](Sample *x, const uint8_t &y){x->syringe2 = y;},
	    "");
	
	vSample.def_property("custom",
	    [](const Sample &x){return ascii_to_unicode_safe(x.custom);},
	    [](Sample &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}