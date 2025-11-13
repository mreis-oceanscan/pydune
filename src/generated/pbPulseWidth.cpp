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

void pbPulseWidth(py::module &m) {
	auto vPulseWidth = py::class_<PulseWidth, Message>(m, "PulseWidth", "Pulse Width");
	vPulseWidth.def(py::init<>());
	vPulseWidth.def("__setstate__", &pbUnpickleMessage<PulseWidth>);
	vPulseWidth.def_readwrite("value", &PulseWidth::value);
}