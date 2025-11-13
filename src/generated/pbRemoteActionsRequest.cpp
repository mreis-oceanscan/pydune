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

void pbRemoteActionsRequest(py::module &m) {
	auto vRemoteActionsRequest = py::class_<RemoteActionsRequest, Message>(m, "RemoteActionsRequest", "Remote Actions Request");
	vRemoteActionsRequest.def(py::init<>());
	vRemoteActionsRequest.def("__setstate__", &pbUnpickleMessage<RemoteActionsRequest>);
	
	vRemoteActionsRequest.def_property("op",
	    [](const RemoteActionsRequest &x){return static_cast<RemoteActionsRequest::operationEnum>(x.op);},
	    [](RemoteActionsRequest *x, const uint8_t &y){x->op = y;},
	    "");
	
	vRemoteActionsRequest.def_property("actions",
	    [](const RemoteActionsRequest &x){return ascii_to_unicode_safe(x.actions);},
	    [](RemoteActionsRequest &x, std::string &s){x.actions = s;}, py::return_value_policy::take_ownership);

	py::enum_<RemoteActionsRequest::operationEnum>(vRemoteActionsRequest, "OperationEnum", "operation")
		.value("REPORT", RemoteActionsRequest::operationEnum::OP_REPORT)
		.value("QUERY", RemoteActionsRequest::operationEnum::OP_QUERY)
		.value("REGISTER", RemoteActionsRequest::operationEnum::OP_REGISTER);
}