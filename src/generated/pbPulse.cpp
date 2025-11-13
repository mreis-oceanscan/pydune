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

void pbPulse(py::module &m) {
	auto vPulse = py::class_<Pulse, Message>(m, "Pulse", "Pulse");
	vPulse.def(py::init<>());
	vPulse.def("__setstate__", &pbUnpickleMessage<Pulse>);
	vPulse.def_readwrite("origin_timestamp", &Pulse::origin_timestamp);
}