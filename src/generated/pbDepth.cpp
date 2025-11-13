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

void pbDepth(py::module &m) {
	auto vDepth = py::class_<Depth, Message>(m, "Depth", "Depth");
	vDepth.def(py::init<>());
	vDepth.def("__setstate__", &pbUnpickleMessage<Depth>);
	vDepth.def_readwrite("value", &Depth::value);
}