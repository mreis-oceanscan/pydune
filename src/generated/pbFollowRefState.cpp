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

void pbFollowRefState(py::module &m) {
	auto vFollowRefState = py::class_<FollowRefState, Message>(m, "FollowRefState", "Follow Reference State");
	vFollowRefState.def(py::init<>());
	vFollowRefState.def("__setstate__", &pbUnpickleMessage<FollowRefState>);
	vFollowRefState.def_readwrite("control_src", &FollowRefState::control_src);
	vFollowRefState.def_readwrite("control_ent", &FollowRefState::control_ent);
	
	vFollowRefState.def_property("reference",
	[](const FollowRefState &x){return x.reference.isNull() ? nullptr : x.reference.get();},
	[](FollowRefState *x, const py::handle &y){
	    if(y.is_none()){
	        x->reference.clear();
	    } else {
	        try {
	            x->reference.set(y.cast<Reference*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Reference or NoneType.");
	        }
	        x->reference.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vFollowRefState.def_property("state",
	    [](const FollowRefState &x){return static_cast<FollowRefState::StateEnum>(x.state);},
	    [](FollowRefState *x, const uint8_t &y){x->state = y;},
	    "");
	vFollowRefState.def_readwrite("proximity", &FollowRefState::proximity);

	py::enum_<FollowRefState::StateEnum>(vFollowRefState, "StateEnum", "State")
		.value("WAIT", FollowRefState::StateEnum::FR_WAIT)
		.value("GOTO", FollowRefState::StateEnum::FR_GOTO)
		.value("LOITER", FollowRefState::StateEnum::FR_LOITER)
		.value("HOVER", FollowRefState::StateEnum::FR_HOVER)
		.value("ELEVATOR", FollowRefState::StateEnum::FR_ELEVATOR)
		.value("TIMEOUT", FollowRefState::StateEnum::FR_TIMEOUT);

	py::enum_<FollowRefState::ProximityBits>(vFollowRefState, "ProximityBits", "Proximity", py::arithmetic())
		.value("FAR", FollowRefState::ProximityBits::PROX_FAR)
		.value("XY_NEAR", FollowRefState::ProximityBits::PROX_XY_NEAR)
		.value("Z_NEAR", FollowRefState::ProximityBits::PROX_Z_NEAR)
		.value("XY_UNREACHABLE", FollowRefState::ProximityBits::PROX_XY_UNREACHABLE)
		.value("Z_UNREACHABLE", FollowRefState::ProximityBits::PROX_Z_UNREACHABLE);
}