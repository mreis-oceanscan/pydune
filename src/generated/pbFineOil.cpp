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

void pbFineOil(py::module &m) {
	auto vFineOil = py::class_<FineOil, Message>(m, "FineOil", "Fine Oil");
	vFineOil.def(py::init<>());
	vFineOil.def("__setstate__", &pbUnpickleMessage<FineOil>);
	vFineOil.def_readwrite("value", &FineOil::value);
}