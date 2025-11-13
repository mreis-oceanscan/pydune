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

void pbFollowReference(py::module &m) {
	auto vFollowReference = py::class_<FollowReference, Maneuver>(m, "FollowReference", "Follow Reference Maneuver");
	vFollowReference.def(py::init<>());
	vFollowReference.def("__setstate__", &pbUnpickleMessage<FollowReference>);
	vFollowReference.def_readwrite("control_src", &FollowReference::control_src);
	vFollowReference.def_readwrite("control_ent", &FollowReference::control_ent);
	vFollowReference.def_readwrite("timeout", &FollowReference::timeout);
	vFollowReference.def_readwrite("loiter_radius", &FollowReference::loiter_radius);
	vFollowReference.def_readwrite("altitude_interval", &FollowReference::altitude_interval);
}