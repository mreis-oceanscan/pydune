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

void pbFollowCommandState(py::module &m) {
	auto vFollowCommandState = py::class_<FollowCommandState, Message>(m, "FollowCommandState", "Follow Command State");
	vFollowCommandState.def(py::init<>());
	vFollowCommandState.def("__setstate__", &pbUnpickleMessage<FollowCommandState>);
	vFollowCommandState.def_readwrite("control_src", &FollowCommandState::control_src);
	vFollowCommandState.def_readwrite("control_ent", &FollowCommandState::control_ent);
	
	vFollowCommandState.def_property("command",
	[](const FollowCommandState &x){return x.command.isNull() ? nullptr : x.command.get();},
	[](FollowCommandState *x, const py::handle &y){
	    if(y.is_none()){
	        x->command.clear();
	    } else {
	        try {
	            x->command.set(y.cast<Command*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Command or NoneType.");
	        }
	        x->command.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vFollowCommandState.def_property("state",
	    [](const FollowCommandState &x){return static_cast<FollowCommandState::StateEnum>(x.state);},
	    [](FollowCommandState *x, const uint8_t &y){x->state = y;},
	    "");

	py::enum_<FollowCommandState::StateEnum>(vFollowCommandState, "StateEnum", "State")
		.value("WAIT", FollowCommandState::StateEnum::FC_WAIT)
		.value("MOVING", FollowCommandState::StateEnum::FC_MOVING)
		.value("STOPPED", FollowCommandState::StateEnum::FC_STOPPED)
		.value("BAD_COMMAND", FollowCommandState::StateEnum::FC_BAD_COMMAND)
		.value("TIMEOUT", FollowCommandState::StateEnum::FC_TIMEOUT);
}