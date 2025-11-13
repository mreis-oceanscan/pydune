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

void pbAirSaturation(py::module &m) {
	auto vAirSaturation = py::class_<AirSaturation, Message>(m, "AirSaturation", "Air Saturation");
	vAirSaturation.def(py::init<>());
	vAirSaturation.def("__setstate__", &pbUnpickleMessage<AirSaturation>);
	vAirSaturation.def_readwrite("value", &AirSaturation::value);
}