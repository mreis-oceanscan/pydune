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

void pbTemperature(py::module &m) {
	auto vTemperature = py::class_<Temperature, Message>(m, "Temperature", "Temperature");
	vTemperature.def(py::init<>());
	vTemperature.def("__setstate__", &pbUnpickleMessage<Temperature>);
	vTemperature.def_readwrite("value", &Temperature::value);
}