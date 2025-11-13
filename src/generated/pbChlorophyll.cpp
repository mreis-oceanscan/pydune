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

void pbChlorophyll(py::module &m) {
	auto vChlorophyll = py::class_<Chlorophyll, Message>(m, "Chlorophyll", "Chlorophyll");
	vChlorophyll.def(py::init<>());
	vChlorophyll.def("__setstate__", &pbUnpickleMessage<Chlorophyll>);
	vChlorophyll.def_readwrite("value", &Chlorophyll::value);
}