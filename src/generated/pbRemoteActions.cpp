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

void pbRemoteActions(py::module &m) {
	auto vRemoteActions = py::class_<RemoteActions, Message>(m, "RemoteActions", "Remote Actions");
	vRemoteActions.def(py::init<>());
	vRemoteActions.def("__setstate__", &pbUnpickleMessage<RemoteActions>);
	
	vRemoteActions.def_property("actions",
	    [](const RemoteActions &x){return ascii_to_unicode_safe(x.actions);},
	    [](RemoteActions &x, std::string &s){x.actions = s;}, py::return_value_policy::take_ownership);
}