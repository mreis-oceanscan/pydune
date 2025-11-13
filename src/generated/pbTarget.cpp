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

void pbTarget(py::module &m) {
	auto vTarget = py::class_<Target, Message>(m, "Target", "Target");
	vTarget.def(py::init<>());
	vTarget.def("__setstate__", &pbUnpickleMessage<Target>);
	
	vTarget.def_property("label",
	    [](const Target &x){return ascii_to_unicode_safe(x.label);},
	    [](Target &x, std::string &s){x.label = s;}, py::return_value_policy::take_ownership);
	vTarget.def_readwrite("lat", &Target::lat);
	vTarget.def_readwrite("lon", &Target::lon);
	vTarget.def_readwrite("z", &Target::z);
	
	vTarget.def_property("z_units",
	    [](const Target &x){return static_cast<ZUnits>(x.z_units);},
	    [](Target *x, const uint8_t &y){x->z_units = y;},
	    "");
	vTarget.def_readwrite("cog", &Target::cog);
	vTarget.def_readwrite("sog", &Target::sog);
}