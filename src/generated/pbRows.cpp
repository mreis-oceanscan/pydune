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

void pbRows(py::module &m) {
	auto vRows = py::class_<Rows, Maneuver>(m, "Rows", "Rows Maneuver");
	vRows.def(py::init<>());
	vRows.def("__setstate__", &pbUnpickleMessage<Rows>);
	vRows.def_readwrite("timeout", &Rows::timeout);
	vRows.def_readwrite("lat", &Rows::lat);
	vRows.def_readwrite("lon", &Rows::lon);
	vRows.def_readwrite("z", &Rows::z);
	
	vRows.def_property("z_units",
	    [](const Rows &x){return static_cast<ZUnits>(x.z_units);},
	    [](Rows *x, const uint8_t &y){x->z_units = y;},
	    "");
	vRows.def_readwrite("speed", &Rows::speed);
	
	vRows.def_property("speed_units",
	    [](const Rows &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Rows *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vRows.def_readwrite("bearing", &Rows::bearing);
	vRows.def_readwrite("cross_angle", &Rows::cross_angle);
	vRows.def_readwrite("width", &Rows::width);
	vRows.def_readwrite("length", &Rows::length);
	vRows.def_readwrite("hstep", &Rows::hstep);
	vRows.def_readwrite("coff", &Rows::coff);
	vRows.def_readwrite("alternation", &Rows::alternation);
	vRows.def_readwrite("flags", &Rows::flags);
	
	vRows.def_property("custom",
	    [](const Rows &x){return ascii_to_unicode_safe(x.custom);},
	    [](Rows &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<Rows::FlagsBits>(vRows, "FlagsBits", "Flags", py::arithmetic())
		.value("SQUARE_CURVE", Rows::FlagsBits::FLG_SQUARE_CURVE)
		.value("CURVE_RIGHT", Rows::FlagsBits::FLG_CURVE_RIGHT);
}