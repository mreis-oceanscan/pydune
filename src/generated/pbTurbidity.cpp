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

void pbTurbidity(py::module &m) {
	auto vTurbidity = py::class_<Turbidity, Message>(m, "Turbidity", "Turbidity");
	vTurbidity.def(py::init<>());
	vTurbidity.def("__setstate__", &pbUnpickleMessage<Turbidity>);
	vTurbidity.def_readwrite("value", &Turbidity::value);
}