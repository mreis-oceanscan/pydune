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

void pbLeaderState(py::module &m) {
	auto vLeaderState = py::class_<LeaderState, Message>(m, "LeaderState", "Leader State");
	vLeaderState.def(py::init<>());
	vLeaderState.def("__setstate__", &pbUnpickleMessage<LeaderState>);
	
	vLeaderState.def_property("group_name",
	    [](const LeaderState &x){return ascii_to_unicode_safe(x.group_name);},
	    [](LeaderState &x, std::string &s){x.group_name = s;}, py::return_value_policy::take_ownership);
	
	vLeaderState.def_property("op",
	    [](const LeaderState &x){return static_cast<LeaderState::ActionontheleaderstateEnum>(x.op);},
	    [](LeaderState *x, const uint8_t &y){x->op = y;},
	    "");
	vLeaderState.def_readwrite("lat", &LeaderState::lat);
	vLeaderState.def_readwrite("lon", &LeaderState::lon);
	vLeaderState.def_readwrite("height", &LeaderState::height);
	vLeaderState.def_readwrite("x", &LeaderState::x);
	vLeaderState.def_readwrite("y", &LeaderState::y);
	vLeaderState.def_readwrite("z", &LeaderState::z);
	vLeaderState.def_readwrite("phi", &LeaderState::phi);
	vLeaderState.def_readwrite("theta", &LeaderState::theta);
	vLeaderState.def_readwrite("psi", &LeaderState::psi);
	vLeaderState.def_readwrite("vx", &LeaderState::vx);
	vLeaderState.def_readwrite("vy", &LeaderState::vy);
	vLeaderState.def_readwrite("vz", &LeaderState::vz);
	vLeaderState.def_readwrite("p", &LeaderState::p);
	vLeaderState.def_readwrite("q", &LeaderState::q);
	vLeaderState.def_readwrite("r", &LeaderState::r);
	vLeaderState.def_readwrite("svx", &LeaderState::svx);
	vLeaderState.def_readwrite("svy", &LeaderState::svy);
	vLeaderState.def_readwrite("svz", &LeaderState::svz);

	py::enum_<LeaderState::ActionontheleaderstateEnum>(vLeaderState, "ActionOnTheLeaderStateEnum", "Action on the leader state")
		.value("REQUEST", LeaderState::ActionontheleaderstateEnum::OP_REQUEST)
		.value("SET", LeaderState::ActionontheleaderstateEnum::OP_SET)
		.value("REPORT", LeaderState::ActionontheleaderstateEnum::OP_REPORT);
}