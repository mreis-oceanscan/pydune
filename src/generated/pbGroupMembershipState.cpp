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

void pbGroupMembershipState(py::module &m) {
	auto vGroupMembershipState = py::class_<GroupMembershipState, Message>(m, "GroupMembershipState", "Group Membership State");
	vGroupMembershipState.def(py::init<>());
	vGroupMembershipState.def("__setstate__", &pbUnpickleMessage<GroupMembershipState>);
	
	vGroupMembershipState.def_property("group_name",
	    [](const GroupMembershipState &x){return ascii_to_unicode_safe(x.group_name);},
	    [](GroupMembershipState &x, std::string &s){x.group_name = s;}, py::return_value_policy::take_ownership);
	vGroupMembershipState.def_readwrite("links", &GroupMembershipState::links);
}