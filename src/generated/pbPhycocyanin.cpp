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

void pbPhycocyanin(py::module &m) {
	auto vPhycocyanin = py::class_<Phycocyanin, Message>(m, "Phycocyanin", "Phycocyanin");
	vPhycocyanin.def(py::init<>());
	vPhycocyanin.def("__setstate__", &pbUnpickleMessage<Phycocyanin>);
	vPhycocyanin.def_readwrite("value", &Phycocyanin::value);
}