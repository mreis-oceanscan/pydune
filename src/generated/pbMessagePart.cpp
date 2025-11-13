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

void pbMessagePart(py::module &m) {
	auto vMessagePart = py::class_<MessagePart, Message>(m, "MessagePart", "Message Fragment");
	vMessagePart.def(py::init<>());
	vMessagePart.def("__setstate__", &pbUnpickleMessage<MessagePart>);
	vMessagePart.def_readwrite("uid", &MessagePart::uid);
	vMessagePart.def_readwrite("frag_number", &MessagePart::frag_number);
	vMessagePart.def_readwrite("num_frags", &MessagePart::num_frags);
	
	vMessagePart.def_property("data",
	    [](const MessagePart &x){return py::bytes(x.data.data(), x.data.size());},
	    [](MessagePart &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}