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

void pbPathControlState(py::module &m) {
	auto vPathControlState = py::class_<PathControlState, Message>(m, "PathControlState", "Path Control State");
	vPathControlState.def(py::init<>());
	vPathControlState.def("__setstate__", &pbUnpickleMessage<PathControlState>);
	vPathControlState.def_readwrite("path_ref", &PathControlState::path_ref);
	vPathControlState.def_readwrite("start_lat", &PathControlState::start_lat);
	vPathControlState.def_readwrite("start_lon", &PathControlState::start_lon);
	vPathControlState.def_readwrite("start_z", &PathControlState::start_z);
	
	vPathControlState.def_property("start_z_units",
	    [](const PathControlState &x){return static_cast<ZUnits>(x.start_z_units);},
	    [](PathControlState *x, const uint8_t &y){x->start_z_units = y;},
	    "");
	vPathControlState.def_readwrite("end_lat", &PathControlState::end_lat);
	vPathControlState.def_readwrite("end_lon", &PathControlState::end_lon);
	vPathControlState.def_readwrite("end_z", &PathControlState::end_z);
	
	vPathControlState.def_property("end_z_units",
	    [](const PathControlState &x){return static_cast<ZUnits>(x.end_z_units);},
	    [](PathControlState *x, const uint8_t &y){x->end_z_units = y;},
	    "");
	vPathControlState.def_readwrite("lradius", &PathControlState::lradius);
	vPathControlState.def_readwrite("flags", &PathControlState::flags);
	vPathControlState.def_readwrite("x", &PathControlState::x);
	vPathControlState.def_readwrite("y", &PathControlState::y);
	vPathControlState.def_readwrite("z", &PathControlState::z);
	vPathControlState.def_readwrite("vx", &PathControlState::vx);
	vPathControlState.def_readwrite("vy", &PathControlState::vy);
	vPathControlState.def_readwrite("vz", &PathControlState::vz);
	vPathControlState.def_readwrite("course_error", &PathControlState::course_error);
	vPathControlState.def_readwrite("eta", &PathControlState::eta);

	py::enum_<PathControlState::FlagsBits>(vPathControlState, "FlagsBits", "Flags", py::arithmetic())
		.value("NEAR", PathControlState::FlagsBits::FL_NEAR)
		.value("LOITERING", PathControlState::FlagsBits::FL_LOITERING)
		.value("NO_Z", PathControlState::FlagsBits::FL_NO_Z)
		.value("_3DTRACK", PathControlState::FlagsBits::FL_3DTRACK)
		.value("CCLOCKW", PathControlState::FlagsBits::FL_CCLOCKW);
}