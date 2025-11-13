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

void pbTDS(py::module &m) {
	auto vTDS = py::class_<TDS, Message>(m, "TDS", "Total Dissolved Solids");
	vTDS.def(py::init<>());
	vTDS.def("__setstate__", &pbUnpickleMessage<TDS>);
	vTDS.def_readwrite("value", &TDS::value);
}