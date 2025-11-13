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

void pbOpticalBackscatter(py::module &m) {
	auto vOpticalBackscatter = py::class_<OpticalBackscatter, Message>(m, "OpticalBackscatter", "Optical Backscattering Coefficient");
	vOpticalBackscatter.def(py::init<>());
	vOpticalBackscatter.def("__setstate__", &pbUnpickleMessage<OpticalBackscatter>);
	vOpticalBackscatter.def_readwrite("value", &OpticalBackscatter::value);
}