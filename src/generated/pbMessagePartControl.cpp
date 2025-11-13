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

void pbMessagePartControl(py::module &m) {
	auto vMessagePartControl = py::class_<MessagePartControl, Message>(m, "MessagePartControl", "Message Fragment Control");
	vMessagePartControl.def(py::init<>());
	vMessagePartControl.def("__setstate__", &pbUnpickleMessage<MessagePartControl>);
	vMessagePartControl.def_readwrite("uid", &MessagePartControl::uid);
	
	vMessagePartControl.def_property("op",
	    [](const MessagePartControl &x){return static_cast<MessagePartControl::OperationEnum>(x.op);},
	    [](MessagePartControl *x, const uint8_t &y){x->op = y;},
	    "");
	
	vMessagePartControl.def_property("frag_ids",
	    [](const MessagePartControl &x){return ascii_to_unicode_safe(x.frag_ids);},
	    [](MessagePartControl &x, std::string &s){x.frag_ids = s;}, py::return_value_policy::take_ownership);

	py::enum_<MessagePartControl::OperationEnum>(vMessagePartControl, "OperationEnum", "Operation")
		.value("STATUS_RECEIVED", MessagePartControl::OperationEnum::OP_STATUS_RECEIVED)
		.value("REQUEST_RETRANSMIT", MessagePartControl::OperationEnum::OP_REQUEST_RETRANSMIT);
}