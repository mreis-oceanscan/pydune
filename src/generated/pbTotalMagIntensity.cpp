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

void pbTotalMagIntensity(py::module &m) {
	auto vTotalMagIntensity = py::class_<TotalMagIntensity, Message>(m, "TotalMagIntensity", "Total Magnetic Field Intensity");
	vTotalMagIntensity.def(py::init<>());
	vTotalMagIntensity.def("__setstate__", &pbUnpickleMessage<TotalMagIntensity>);
	vTotalMagIntensity.def_readwrite("value", &TotalMagIntensity::value);
}