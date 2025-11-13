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

void pbPhycoerythrin(py::module &m) {
	auto vPhycoerythrin = py::class_<Phycoerythrin, Message>(m, "Phycoerythrin", "Phycoerythrin");
	vPhycoerythrin.def(py::init<>());
	vPhycoerythrin.def("__setstate__", &pbUnpickleMessage<Phycoerythrin>);
	vPhycoerythrin.def_readwrite("value", &Phycoerythrin::value);
}