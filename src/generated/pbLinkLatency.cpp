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

void pbLinkLatency(py::module &m) {
	auto vLinkLatency = py::class_<LinkLatency, Message>(m, "LinkLatency", "Link Latency");
	vLinkLatency.def(py::init<>());
	vLinkLatency.def("__setstate__", &pbUnpickleMessage<LinkLatency>);
	vLinkLatency.def_readwrite("value", &LinkLatency::value);
	vLinkLatency.def_readwrite("sys_src", &LinkLatency::sys_src);
}