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

void pbConductivity(py::module &m) {
	auto vConductivity = py::class_<Conductivity, Message>(m, "Conductivity", "Conductivity");
	vConductivity.def(py::init<>());
	vConductivity.def("__setstate__", &pbUnpickleMessage<Conductivity>);
	vConductivity.def_readwrite("value", &Conductivity::value);
}