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

void pbAbort(py::module &m) {
	auto vAbort = py::class_<Abort, Message>(m, "Abort", "Abort");
	vAbort.def(py::init<>());
	vAbort.def("__setstate__", &pbUnpickleMessage<Abort>);
}