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

void pbFluorescein(py::module &m) {
	auto vFluorescein = py::class_<Fluorescein, Message>(m, "Fluorescein", "Fluorescein");
	vFluorescein.def(py::init<>());
	vFluorescein.def("__setstate__", &pbUnpickleMessage<Fluorescein>);
	vFluorescein.def_readwrite("value", &Fluorescein::value);
}