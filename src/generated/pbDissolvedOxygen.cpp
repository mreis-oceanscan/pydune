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

void pbDissolvedOxygen(py::module &m) {
	auto vDissolvedOxygen = py::class_<DissolvedOxygen, Message>(m, "DissolvedOxygen", "Dissolved Oxygen");
	vDissolvedOxygen.def(py::init<>());
	vDissolvedOxygen.def("__setstate__", &pbUnpickleMessage<DissolvedOxygen>);
	vDissolvedOxygen.def_readwrite("value", &DissolvedOxygen::value);
}