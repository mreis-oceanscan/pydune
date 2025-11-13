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

void pbRemoteState(py::module &m) {
	auto vRemoteState = py::class_<RemoteState, Message>(m, "RemoteState", "Remote State");
	vRemoteState.def(py::init<>());
	vRemoteState.def("__setstate__", &pbUnpickleMessage<RemoteState>);
	vRemoteState.def_readwrite("lat", &RemoteState::lat);
	vRemoteState.def_readwrite("lon", &RemoteState::lon);
	vRemoteState.def_readwrite("depth", &RemoteState::depth);
	vRemoteState.def_readwrite("speed", &RemoteState::speed);
	vRemoteState.def_readwrite("psi", &RemoteState::psi);
}