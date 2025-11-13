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

void pbDesiredPath(py::module &m) {
	auto vDesiredPath = py::class_<DesiredPath, ControlCommand>(m, "DesiredPath", "Desired Path");
	vDesiredPath.def(py::init<>());
	vDesiredPath.def("__setstate__", &pbUnpickleMessage<DesiredPath>);
	vDesiredPath.def_readwrite("path_ref", &DesiredPath::path_ref);
	vDesiredPath.def_readwrite("start_lat", &DesiredPath::start_lat);
	vDesiredPath.def_readwrite("start_lon", &DesiredPath::start_lon);
	vDesiredPath.def_readwrite("start_z", &DesiredPath::start_z);
	
	vDesiredPath.def_property("start_z_units",
	    [](const DesiredPath &x){return static_cast<ZUnits>(x.start_z_units);},
	    [](DesiredPath *x, const uint8_t &y){x->start_z_units = y;},
	    "");
	vDesiredPath.def_readwrite("end_lat", &DesiredPath::end_lat);
	vDesiredPath.def_readwrite("end_lon", &DesiredPath::end_lon);
	vDesiredPath.def_readwrite("end_z", &DesiredPath::end_z);
	
	vDesiredPath.def_property("end_z_units",
	    [](const DesiredPath &x){return static_cast<ZUnits>(x.end_z_units);},
	    [](DesiredPath *x, const uint8_t &y){x->end_z_units = y;},
	    "");
	vDesiredPath.def_readwrite("speed", &DesiredPath::speed);
	
	vDesiredPath.def_property("speed_units",
	    [](const DesiredPath &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](DesiredPath *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vDesiredPath.def_readwrite("lradius", &DesiredPath::lradius);
	vDesiredPath.def_readwrite("flags", &DesiredPath::flags);

	py::enum_<DesiredPath::FlagsBits>(vDesiredPath, "FlagsBits", "Flags", py::arithmetic())
		.value("START", DesiredPath::FlagsBits::FL_START)
		.value("DIRECT", DesiredPath::FlagsBits::FL_DIRECT)
		.value("NO_Z", DesiredPath::FlagsBits::FL_NO_Z)
		.value("_3DTRACK", DesiredPath::FlagsBits::FL_3DTRACK)
		.value("CCLOCKW", DesiredPath::FlagsBits::FL_CCLOCKW)
		.value("LOITER_CURR", DesiredPath::FlagsBits::FL_LOITER_CURR)
		.value("TAKEOFF", DesiredPath::FlagsBits::FL_TAKEOFF)
		.value("LAND", DesiredPath::FlagsBits::FL_LAND);
}