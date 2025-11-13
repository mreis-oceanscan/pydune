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

void pbIdleManeuver(py::module &m) {
	auto vIdleManeuver = py::class_<IdleManeuver, Maneuver>(m, "IdleManeuver", "Idle Maneuver");
	vIdleManeuver.def(py::init<>());
	vIdleManeuver.def("__setstate__", &pbUnpickleMessage<IdleManeuver>);
	vIdleManeuver.def_readwrite("duration", &IdleManeuver::duration);
	
	vIdleManeuver.def_property("custom",
	    [](const IdleManeuver &x){return ascii_to_unicode_safe(x.custom);},
	    [](IdleManeuver &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}