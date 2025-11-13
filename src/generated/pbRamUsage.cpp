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

void pbRamUsage(py::module &m) {
	auto vRamUsage = py::class_<RamUsage, Message>(m, "RamUsage", "RAM Usage");
	vRamUsage.def(py::init<>());
	vRamUsage.def("__setstate__", &pbUnpickleMessage<RamUsage>);
	vRamUsage.def_readwrite("value", &RamUsage::value);
}