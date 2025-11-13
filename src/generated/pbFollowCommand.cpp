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

void pbFollowCommand(py::module &m) {
	auto vFollowCommand = py::class_<FollowCommand, Maneuver>(m, "FollowCommand", "Follow Command Maneuver");
	vFollowCommand.def(py::init<>());
	vFollowCommand.def("__setstate__", &pbUnpickleMessage<FollowCommand>);
	vFollowCommand.def_readwrite("control_src", &FollowCommand::control_src);
	vFollowCommand.def_readwrite("control_ent", &FollowCommand::control_ent);
	vFollowCommand.def_readwrite("timeout", &FollowCommand::timeout);
}