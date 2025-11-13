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

void pbIridiumMsgRx(py::module &m) {
	auto vIridiumMsgRx = py::class_<IridiumMsgRx, Message>(m, "IridiumMsgRx", "Received Iridium Message");
	vIridiumMsgRx.def(py::init<>());
	vIridiumMsgRx.def("__setstate__", &pbUnpickleMessage<IridiumMsgRx>);
	
	vIridiumMsgRx.def_property("origin",
	    [](const IridiumMsgRx &x){return ascii_to_unicode_safe(x.origin);},
	    [](IridiumMsgRx &x, std::string &s){x.origin = s;}, py::return_value_policy::take_ownership);
	vIridiumMsgRx.def_readwrite("htime", &IridiumMsgRx::htime);
	vIridiumMsgRx.def_readwrite("lat", &IridiumMsgRx::lat);
	vIridiumMsgRx.def_readwrite("lon", &IridiumMsgRx::lon);
	
	vIridiumMsgRx.def_property("data",
	    [](const IridiumMsgRx &x){return py::bytes(x.data.data(), x.data.size());},
	    [](IridiumMsgRx &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}