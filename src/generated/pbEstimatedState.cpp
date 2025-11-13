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

void pbEstimatedState(py::module &m) {
	auto vEstimatedState = py::class_<EstimatedState, Message>(m, "EstimatedState", "Estimated State");
	vEstimatedState.def(py::init<>());
	vEstimatedState.def("__setstate__", &pbUnpickleMessage<EstimatedState>);
	vEstimatedState.def_readwrite("lat", &EstimatedState::lat);
	vEstimatedState.def_readwrite("lon", &EstimatedState::lon);
	vEstimatedState.def_readwrite("height", &EstimatedState::height);
	vEstimatedState.def_readwrite("x", &EstimatedState::x);
	vEstimatedState.def_readwrite("y", &EstimatedState::y);
	vEstimatedState.def_readwrite("z", &EstimatedState::z);
	vEstimatedState.def_readwrite("phi", &EstimatedState::phi);
	vEstimatedState.def_readwrite("theta", &EstimatedState::theta);
	vEstimatedState.def_readwrite("psi", &EstimatedState::psi);
	vEstimatedState.def_readwrite("u", &EstimatedState::u);
	vEstimatedState.def_readwrite("v", &EstimatedState::v);
	vEstimatedState.def_readwrite("w", &EstimatedState::w);
	vEstimatedState.def_readwrite("vx", &EstimatedState::vx);
	vEstimatedState.def_readwrite("vy", &EstimatedState::vy);
	vEstimatedState.def_readwrite("vz", &EstimatedState::vz);
	vEstimatedState.def_readwrite("p", &EstimatedState::p);
	vEstimatedState.def_readwrite("q", &EstimatedState::q);
	vEstimatedState.def_readwrite("r", &EstimatedState::r);
	vEstimatedState.def_readwrite("depth", &EstimatedState::depth);
	vEstimatedState.def_readwrite("alt", &EstimatedState::alt);
}