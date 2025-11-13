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

void pbPopUp(py::module &m) {
	auto vPopUp = py::class_<PopUp, Maneuver>(m, "PopUp", "PopUp Maneuver");
	vPopUp.def(py::init<>());
	vPopUp.def("__setstate__", &pbUnpickleMessage<PopUp>);
	vPopUp.def_readwrite("timeout", &PopUp::timeout);
	vPopUp.def_readwrite("lat", &PopUp::lat);
	vPopUp.def_readwrite("lon", &PopUp::lon);
	vPopUp.def_readwrite("z", &PopUp::z);
	
	vPopUp.def_property("z_units",
	    [](const PopUp &x){return static_cast<ZUnits>(x.z_units);},
	    [](PopUp *x, const uint8_t &y){x->z_units = y;},
	    "");
	vPopUp.def_readwrite("speed", &PopUp::speed);
	
	vPopUp.def_property("speed_units",
	    [](const PopUp &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](PopUp *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vPopUp.def_readwrite("duration", &PopUp::duration);
	vPopUp.def_readwrite("radius", &PopUp::radius);
	vPopUp.def_readwrite("flags", &PopUp::flags);
	
	vPopUp.def_property("custom",
	    [](const PopUp &x){return ascii_to_unicode_safe(x.custom);},
	    [](PopUp &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<PopUp::FlagsBits>(vPopUp, "FlagsBits", "Flags", py::arithmetic())
		.value("CURR_POS", PopUp::FlagsBits::FLG_CURR_POS)
		.value("WAIT_AT_SURFACE", PopUp::FlagsBits::FLG_WAIT_AT_SURFACE)
		.value("STATION_KEEP", PopUp::FlagsBits::FLG_STATION_KEEP);
}