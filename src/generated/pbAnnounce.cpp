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

void pbAnnounce(py::module &m) {
	auto vAnnounce = py::class_<Announce, Message>(m, "Announce", "Announce");
	vAnnounce.def(py::init<>());
	vAnnounce.def("__setstate__", &pbUnpickleMessage<Announce>);
	
	vAnnounce.def_property("sys_name",
	    [](const Announce &x){return ascii_to_unicode_safe(x.sys_name);},
	    [](Announce &x, std::string &s){x.sys_name = s;}, py::return_value_policy::take_ownership);
	
	vAnnounce.def_property("sys_type",
	    [](const Announce &x){return static_cast<SystemType>(x.sys_type);},
	    [](Announce *x, const uint8_t &y){x->sys_type = y;},
	    "");
	vAnnounce.def_readwrite("owner", &Announce::owner);
	vAnnounce.def_readwrite("lat", &Announce::lat);
	vAnnounce.def_readwrite("lon", &Announce::lon);
	vAnnounce.def_readwrite("height", &Announce::height);
	
	vAnnounce.def_property("services",
	    [](const Announce &x){return ascii_to_unicode_safe(x.services);},
	    [](Announce &x, std::string &s){x.services = s;}, py::return_value_policy::take_ownership);
}