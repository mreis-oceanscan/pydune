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

void pbMagnetometer(py::module &m) {
	auto vMagnetometer = py::class_<Magnetometer, Maneuver>(m, "Magnetometer", "Magnetometer Maneuver");
	vMagnetometer.def(py::init<>());
	vMagnetometer.def("__setstate__", &pbUnpickleMessage<Magnetometer>);
	vMagnetometer.def_readwrite("timeout", &Magnetometer::timeout);
	vMagnetometer.def_readwrite("lat", &Magnetometer::lat);
	vMagnetometer.def_readwrite("lon", &Magnetometer::lon);
	vMagnetometer.def_readwrite("z", &Magnetometer::z);
	
	vMagnetometer.def_property("z_units",
	    [](const Magnetometer &x){return static_cast<ZUnits>(x.z_units);},
	    [](Magnetometer *x, const uint8_t &y){x->z_units = y;},
	    "");
	vMagnetometer.def_readwrite("speed", &Magnetometer::speed);
	
	vMagnetometer.def_property("speed_units",
	    [](const Magnetometer &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Magnetometer *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vMagnetometer.def_readwrite("bearing", &Magnetometer::bearing);
	vMagnetometer.def_readwrite("width", &Magnetometer::width);
	
	vMagnetometer.def_property("direction",
	    [](const Magnetometer &x){return static_cast<Magnetometer::DirectionEnum>(x.direction);},
	    [](Magnetometer *x, const uint8_t &y){x->direction = y;},
	    "");
	
	vMagnetometer.def_property("custom",
	    [](const Magnetometer &x){return ascii_to_unicode_safe(x.custom);},
	    [](Magnetometer &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<Magnetometer::DirectionEnum>(vMagnetometer, "DirectionEnum", "Direction")
		.value("CLOCKW_FIRST", Magnetometer::DirectionEnum::MD_CLOCKW_FIRST)
		.value("CCLOCKW_FIRST", Magnetometer::DirectionEnum::MD_CCLOCKW_FIRST);
}