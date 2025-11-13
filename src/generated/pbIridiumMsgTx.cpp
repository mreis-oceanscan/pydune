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

void pbIridiumMsgTx(py::module &m) {
	auto vIridiumMsgTx = py::class_<IridiumMsgTx, Message>(m, "IridiumMsgTx", "Transmit Iridium Message");
	vIridiumMsgTx.def(py::init<>());
	vIridiumMsgTx.def("__setstate__", &pbUnpickleMessage<IridiumMsgTx>);
	vIridiumMsgTx.def_readwrite("req_id", &IridiumMsgTx::req_id);
	vIridiumMsgTx.def_readwrite("ttl", &IridiumMsgTx::ttl);
	
	vIridiumMsgTx.def_property("destination",
	    [](const IridiumMsgTx &x){return ascii_to_unicode_safe(x.destination);},
	    [](IridiumMsgTx &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	
	vIridiumMsgTx.def_property("data",
	    [](const IridiumMsgTx &x){return py::bytes(x.data.data(), x.data.size());},
	    [](IridiumMsgTx &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}