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

void pbVSWR(py::module &m) {
	auto vVSWR = py::class_<VSWR, Message>(m, "VSWR", "Voltage Standing Wave Ratio");
	vVSWR.def(py::init<>());
	vVSWR.def("__setstate__", &pbUnpickleMessage<VSWR>);
	vVSWR.def_readwrite("value", &VSWR::value);
}