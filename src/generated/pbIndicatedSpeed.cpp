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

void pbIndicatedSpeed(py::module &m) {
	auto vIndicatedSpeed = py::class_<IndicatedSpeed, Message>(m, "IndicatedSpeed", "Indicated Speed");
	vIndicatedSpeed.def(py::init<>());
	vIndicatedSpeed.def("__setstate__", &pbUnpickleMessage<IndicatedSpeed>);
	vIndicatedSpeed.def_readwrite("value", &IndicatedSpeed::value);
}