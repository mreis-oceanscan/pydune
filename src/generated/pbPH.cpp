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

void pbPH(py::module &m) {
	auto vPH = py::class_<PH, Message>(m, "PH", "pH");
	vPH.def(py::init<>());
	vPH.def("__setstate__", &pbUnpickleMessage<PH>);
	vPH.def_readwrite("value", &PH::value);
}