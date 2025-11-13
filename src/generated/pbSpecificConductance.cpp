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

void pbSpecificConductance(py::module &m) {
	auto vSpecificConductance = py::class_<SpecificConductance, Message>(m, "SpecificConductance", "Specific Conductance");
	vSpecificConductance.def(py::init<>());
	vSpecificConductance.def("__setstate__", &pbUnpickleMessage<SpecificConductance>);
	vSpecificConductance.def_readwrite("value", &SpecificConductance::value);
}