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

void pbManeuverResumed(py::module &m) {
	auto vManeuverResumed = py::class_<ManeuverResumed, Message>(m, "ManeuverResumed", "Maneuver Resumed");
	vManeuverResumed.def(py::init<>());
	vManeuverResumed.def("__setstate__", &pbUnpickleMessage<ManeuverResumed>);
	
	vManeuverResumed.def_property("man_id",
	    [](const ManeuverResumed &x){return ascii_to_unicode_safe(x.man_id);},
	    [](ManeuverResumed &x, std::string &s){x.man_id = s;}, py::return_value_policy::take_ownership);
	vManeuverResumed.def_readwrite("man_list", &ManeuverResumed::man_list);
}