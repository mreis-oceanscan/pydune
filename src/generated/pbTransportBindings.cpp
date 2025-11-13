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

void pbTransportBindings(py::module &m) {
	auto vTransportBindings = py::class_<TransportBindings, Message>(m, "TransportBindings", "Transport Bindings");
	vTransportBindings.def(py::init<>());
	vTransportBindings.def("__setstate__", &pbUnpickleMessage<TransportBindings>);
	
	vTransportBindings.def_property("consumer",
	    [](const TransportBindings &x){return ascii_to_unicode_safe(x.consumer);},
	    [](TransportBindings &x, std::string &s){x.consumer = s;}, py::return_value_policy::take_ownership);
	vTransportBindings.def_readwrite("message_id", &TransportBindings::message_id);
}