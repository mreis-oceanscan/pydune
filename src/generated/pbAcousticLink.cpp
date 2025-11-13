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

void pbAcousticLink(py::module &m) {
	auto vAcousticLink = py::class_<AcousticLink, Message>(m, "AcousticLink", "Acoustic Link Quality");
	vAcousticLink.def(py::init<>());
	vAcousticLink.def("__setstate__", &pbUnpickleMessage<AcousticLink>);
	
	vAcousticLink.def_property("peer",
	    [](const AcousticLink &x){return ascii_to_unicode_safe(x.peer);},
	    [](AcousticLink &x, std::string &s){x.peer = s;}, py::return_value_policy::take_ownership);
	vAcousticLink.def_readwrite("rssi", &AcousticLink::rssi);
	vAcousticLink.def_readwrite("integrity", &AcousticLink::integrity);
}