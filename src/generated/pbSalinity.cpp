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

void pbSalinity(py::module &m) {
	auto vSalinity = py::class_<Salinity, Message>(m, "Salinity", "Salinity");
	vSalinity.def(py::init<>());
	vSalinity.def("__setstate__", &pbUnpickleMessage<Salinity>);
	vSalinity.def_readwrite("value", &Salinity::value);
}