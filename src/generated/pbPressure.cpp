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

void pbPressure(py::module &m) {
	auto vPressure = py::class_<Pressure, Message>(m, "Pressure", "Pressure");
	vPressure.def(py::init<>());
	vPressure.def("__setstate__", &pbUnpickleMessage<Pressure>);
	vPressure.def_readwrite("value", &Pressure::value);
}