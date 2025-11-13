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

void pbLinkLevel(py::module &m) {
	auto vLinkLevel = py::class_<LinkLevel, Message>(m, "LinkLevel", "Link Level");
	vLinkLevel.def(py::init<>());
	vLinkLevel.def("__setstate__", &pbUnpickleMessage<LinkLevel>);
	vLinkLevel.def_readwrite("value", &LinkLevel::value);
}