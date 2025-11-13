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

void pbSessionSubscription(py::module &m) {
	auto vSessionSubscription = py::class_<SessionSubscription, Message>(m, "SessionSubscription", "Session Subscription");
	vSessionSubscription.def(py::init<>());
	vSessionSubscription.def("__setstate__", &pbUnpickleMessage<SessionSubscription>);
	vSessionSubscription.def_readwrite("sessid", &SessionSubscription::sessid);
	
	vSessionSubscription.def_property("messages",
	    [](const SessionSubscription &x){return ascii_to_unicode_safe(x.messages);},
	    [](SessionSubscription &x, std::string &s){x.messages = s;}, py::return_value_policy::take_ownership);
}