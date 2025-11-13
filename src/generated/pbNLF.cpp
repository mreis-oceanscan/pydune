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

void pbNLF(py::module &m) {
	auto vNLF = py::class_<NLF, Message>(m, "NLF", "Non-linear Function Conductivity");
	vNLF.def(py::init<>());
	vNLF.def("__setstate__", &pbUnpickleMessage<NLF>);
	vNLF.def_readwrite("value", &NLF::value);
}