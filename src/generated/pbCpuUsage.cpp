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

void pbCpuUsage(py::module &m) {
	auto vCpuUsage = py::class_<CpuUsage, Message>(m, "CpuUsage", "CPU Usage");
	vCpuUsage.def(py::init<>());
	vCpuUsage.def("__setstate__", &pbUnpickleMessage<CpuUsage>);
	vCpuUsage.def_readwrite("value", &CpuUsage::value);
}