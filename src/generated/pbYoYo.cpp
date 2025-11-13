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

void pbYoYo(py::module &m) {
	auto vYoYo = py::class_<YoYo, Maneuver>(m, "YoYo", "Yo-Yo Maneuver");
	vYoYo.def(py::init<>());
	vYoYo.def("__setstate__", &pbUnpickleMessage<YoYo>);
	vYoYo.def_readwrite("timeout", &YoYo::timeout);
	vYoYo.def_readwrite("lat", &YoYo::lat);
	vYoYo.def_readwrite("lon", &YoYo::lon);
	vYoYo.def_readwrite("z", &YoYo::z);
	
	vYoYo.def_property("z_units",
	    [](const YoYo &x){return static_cast<ZUnits>(x.z_units);},
	    [](YoYo *x, const uint8_t &y){x->z_units = y;},
	    "");
	vYoYo.def_readwrite("amplitude", &YoYo::amplitude);
	vYoYo.def_readwrite("pitch", &YoYo::pitch);
	vYoYo.def_readwrite("speed", &YoYo::speed);
	
	vYoYo.def_property("speed_units",
	    [](const YoYo &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](YoYo *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vYoYo.def_property("custom",
	    [](const YoYo &x){return ascii_to_unicode_safe(x.custom);},
	    [](YoYo &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}