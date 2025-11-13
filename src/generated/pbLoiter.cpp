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

void pbLoiter(py::module &m) {
	auto vLoiter = py::class_<Loiter, Maneuver>(m, "Loiter", "Loiter Maneuver");
	vLoiter.def(py::init<>());
	vLoiter.def("__setstate__", &pbUnpickleMessage<Loiter>);
	vLoiter.def_readwrite("timeout", &Loiter::timeout);
	vLoiter.def_readwrite("lat", &Loiter::lat);
	vLoiter.def_readwrite("lon", &Loiter::lon);
	vLoiter.def_readwrite("z", &Loiter::z);
	
	vLoiter.def_property("z_units",
	    [](const Loiter &x){return static_cast<ZUnits>(x.z_units);},
	    [](Loiter *x, const uint8_t &y){x->z_units = y;},
	    "");
	vLoiter.def_readwrite("duration", &Loiter::duration);
	vLoiter.def_readwrite("speed", &Loiter::speed);
	
	vLoiter.def_property("speed_units",
	    [](const Loiter &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Loiter *x, const uint8_t &y){x->speed_units = y;},
	    "");
	
	vLoiter.def_property("type",
	    [](const Loiter &x){return static_cast<Loiter::LoiterTypeEnum>(x.type);},
	    [](Loiter *x, const uint8_t &y){x->type = y;},
	    "");
	vLoiter.def_readwrite("radius", &Loiter::radius);
	vLoiter.def_readwrite("length", &Loiter::length);
	vLoiter.def_readwrite("bearing", &Loiter::bearing);
	
	vLoiter.def_property("direction",
	    [](const Loiter &x){return static_cast<Loiter::DirectionEnum>(x.direction);},
	    [](Loiter *x, const uint8_t &y){x->direction = y;},
	    "");
	
	vLoiter.def_property("custom",
	    [](const Loiter &x){return ascii_to_unicode_safe(x.custom);},
	    [](Loiter &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<Loiter::LoiterTypeEnum>(vLoiter, "LoiterTypeEnum", "Loiter Type")
		.value("DEFAULT", Loiter::LoiterTypeEnum::LT_DEFAULT)
		.value("CIRCULAR", Loiter::LoiterTypeEnum::LT_CIRCULAR)
		.value("RACETRACK", Loiter::LoiterTypeEnum::LT_RACETRACK)
		.value("EIGHT", Loiter::LoiterTypeEnum::LT_EIGHT)
		.value("HOVER", Loiter::LoiterTypeEnum::LT_HOVER);

	py::enum_<Loiter::DirectionEnum>(vLoiter, "DirectionEnum", "Direction")
		.value("VDEP", Loiter::DirectionEnum::LD_VDEP)
		.value("CLOCKW", Loiter::DirectionEnum::LD_CLOCKW)
		.value("CCLOCKW", Loiter::DirectionEnum::LD_CCLOCKW)
		.value("IWINDCURR", Loiter::DirectionEnum::LD_IWINDCURR);
}