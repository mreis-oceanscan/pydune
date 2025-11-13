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

void pbWindSpeed(py::module &m) {
	auto vWindSpeed = py::class_<WindSpeed, Message>(m, "WindSpeed", "Wind Speed");
	vWindSpeed.def(py::init<>());
	vWindSpeed.def("__setstate__", &pbUnpickleMessage<WindSpeed>);
	vWindSpeed.def_readwrite("direction", &WindSpeed::direction);
	vWindSpeed.def_readwrite("speed", &WindSpeed::speed);
	vWindSpeed.def_readwrite("turbulence", &WindSpeed::turbulence);
}