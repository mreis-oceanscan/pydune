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

void pbRelativeHumidity(py::module &m) {
	auto vRelativeHumidity = py::class_<RelativeHumidity, Message>(m, "RelativeHumidity", "Relative Humidity");
	vRelativeHumidity.def(py::init<>());
	vRelativeHumidity.def("__setstate__", &pbUnpickleMessage<RelativeHumidity>);
	vRelativeHumidity.def_readwrite("value", &RelativeHumidity::value);
}