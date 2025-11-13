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

void pbTotalHeading(py::module &m) {
	auto vTotalHeading = py::class_<TotalHeading, Message>(m, "TotalHeading", "Total Heading");
	vTotalHeading.def(py::init<>());
	vTotalHeading.def("__setstate__", &pbUnpickleMessage<TotalHeading>);
	vTotalHeading.def_readwrite("value", &TotalHeading::value);
}