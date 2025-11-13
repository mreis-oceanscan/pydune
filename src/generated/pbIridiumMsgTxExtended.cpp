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

void pbIridiumMsgTxExtended(py::module &m) {
	auto vIridiumMsgTxExtended = py::class_<IridiumMsgTxExtended, Message>(m, "IridiumMsgTxExtended", "Transmit Iridium Message (Extended)");
	vIridiumMsgTxExtended.def(py::init<>());
	vIridiumMsgTxExtended.def("__setstate__", &pbUnpickleMessage<IridiumMsgTxExtended>);
	vIridiumMsgTxExtended.def_readwrite("req_id", &IridiumMsgTxExtended::req_id);
	vIridiumMsgTxExtended.def_readwrite("ttl", &IridiumMsgTxExtended::ttl);
	vIridiumMsgTxExtended.def_readwrite("expiration", &IridiumMsgTxExtended::expiration);
	
	vIridiumMsgTxExtended.def_property("destination",
	    [](const IridiumMsgTxExtended &x){return ascii_to_unicode_safe(x.destination);},
	    [](IridiumMsgTxExtended &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	
	vIridiumMsgTxExtended.def_property("data",
	    [](const IridiumMsgTxExtended &x){return py::bytes(x.data.data(), x.data.size());},
	    [](IridiumMsgTxExtended &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}