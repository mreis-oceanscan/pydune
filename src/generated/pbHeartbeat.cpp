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

void pbHeartbeat(py::module &m) {
	auto vHeartbeat = py::class_<Heartbeat, Message>(m, "Heartbeat", "Heartbeat");
	vHeartbeat.def(py::init<>());
	vHeartbeat.def("__setstate__", &pbUnpickleMessage<Heartbeat>);
}