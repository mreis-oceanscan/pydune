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

void pbRpm(py::module &m) {
	auto vRpm = py::class_<Rpm, Message>(m, "Rpm", "Revolutions Per Minute");
	vRpm.def(py::init<>());
	vRpm.def("__setstate__", &pbUnpickleMessage<Rpm>);
	vRpm.def_readwrite("value", &Rpm::value);
}