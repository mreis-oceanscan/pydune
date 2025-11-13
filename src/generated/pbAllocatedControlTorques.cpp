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

void pbAllocatedControlTorques(py::module &m) {
	auto vAllocatedControlTorques = py::class_<AllocatedControlTorques, Message>(m, "AllocatedControlTorques", "Allocated Control Torques");
	vAllocatedControlTorques.def(py::init<>());
	vAllocatedControlTorques.def("__setstate__", &pbUnpickleMessage<AllocatedControlTorques>);
	vAllocatedControlTorques.def_readwrite("k", &AllocatedControlTorques::k);
	vAllocatedControlTorques.def_readwrite("m", &AllocatedControlTorques::m);
	vAllocatedControlTorques.def_readwrite("n", &AllocatedControlTorques::n);
}