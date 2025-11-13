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

void pbSimulatedState(py::module &m) {
	auto vSimulatedState = py::class_<SimulatedState, Message>(m, "SimulatedState", "Simulated State");
	vSimulatedState.def(py::init<>());
	vSimulatedState.def("__setstate__", &pbUnpickleMessage<SimulatedState>);
	vSimulatedState.def_readwrite("lat", &SimulatedState::lat);
	vSimulatedState.def_readwrite("lon", &SimulatedState::lon);
	vSimulatedState.def_readwrite("height", &SimulatedState::height);
	vSimulatedState.def_readwrite("x", &SimulatedState::x);
	vSimulatedState.def_readwrite("y", &SimulatedState::y);
	vSimulatedState.def_readwrite("z", &SimulatedState::z);
	vSimulatedState.def_readwrite("phi", &SimulatedState::phi);
	vSimulatedState.def_readwrite("theta", &SimulatedState::theta);
	vSimulatedState.def_readwrite("psi", &SimulatedState::psi);
	vSimulatedState.def_readwrite("u", &SimulatedState::u);
	vSimulatedState.def_readwrite("v", &SimulatedState::v);
	vSimulatedState.def_readwrite("w", &SimulatedState::w);
	vSimulatedState.def_readwrite("p", &SimulatedState::p);
	vSimulatedState.def_readwrite("q", &SimulatedState::q);
	vSimulatedState.def_readwrite("r", &SimulatedState::r);
	vSimulatedState.def_readwrite("svx", &SimulatedState::svx);
	vSimulatedState.def_readwrite("svy", &SimulatedState::svy);
	vSimulatedState.def_readwrite("svz", &SimulatedState::svz);
}