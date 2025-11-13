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

void pbDepthOffset(py::module &m) {
	auto vDepthOffset = py::class_<DepthOffset, Message>(m, "DepthOffset", "Depth Offset");
	vDepthOffset.def(py::init<>());
	vDepthOffset.def("__setstate__", &pbUnpickleMessage<DepthOffset>);
	vDepthOffset.def_readwrite("value", &DepthOffset::value);
}