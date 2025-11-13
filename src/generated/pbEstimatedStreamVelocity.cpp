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

void pbEstimatedStreamVelocity(py::module &m) {
	auto vEstimatedStreamVelocity = py::class_<EstimatedStreamVelocity, Message>(m, "EstimatedStreamVelocity", "Estimated Stream Velocity");
	vEstimatedStreamVelocity.def(py::init<>());
	vEstimatedStreamVelocity.def("__setstate__", &pbUnpickleMessage<EstimatedStreamVelocity>);
	vEstimatedStreamVelocity.def_readwrite("x", &EstimatedStreamVelocity::x);
	vEstimatedStreamVelocity.def_readwrite("y", &EstimatedStreamVelocity::y);
	vEstimatedStreamVelocity.def_readwrite("z", &EstimatedStreamVelocity::z);
}