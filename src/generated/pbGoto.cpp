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

void pbGoto(py::module &m) {
	auto vGoto = py::class_<Goto, Maneuver>(m, "Goto", "Goto Maneuver");
	vGoto.def(py::init<>());
	vGoto.def("__setstate__", &pbUnpickleMessage<Goto>);
	vGoto.def_readwrite("timeout", &Goto::timeout);
	vGoto.def_readwrite("lat", &Goto::lat);
	vGoto.def_readwrite("lon", &Goto::lon);
	vGoto.def_readwrite("z", &Goto::z);
	
	vGoto.def_property("z_units",
	    [](const Goto &x){return static_cast<ZUnits>(x.z_units);},
	    [](Goto *x, const uint8_t &y){x->z_units = y;},
	    "");
	vGoto.def_readwrite("speed", &Goto::speed);
	
	vGoto.def_property("speed_units",
	    [](const Goto &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](Goto *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vGoto.def_readwrite("roll", &Goto::roll);
	vGoto.def_readwrite("pitch", &Goto::pitch);
	vGoto.def_readwrite("yaw", &Goto::yaw);
	
	vGoto.def_property("custom",
	    [](const Goto &x){return ascii_to_unicode_safe(x.custom);},
	    [](Goto &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}