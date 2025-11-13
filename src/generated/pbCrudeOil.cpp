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

void pbCrudeOil(py::module &m) {
	auto vCrudeOil = py::class_<CrudeOil, Message>(m, "CrudeOil", "Crude Oil");
	vCrudeOil.def(py::init<>());
	vCrudeOil.def("__setstate__", &pbUnpickleMessage<CrudeOil>);
	vCrudeOil.def_readwrite("value", &CrudeOil::value);
}