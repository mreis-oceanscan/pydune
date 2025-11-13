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

void pbWaterDensity(py::module &m) {
	auto vWaterDensity = py::class_<WaterDensity, Message>(m, "WaterDensity", "Water Density");
	vWaterDensity.def(py::init<>());
	vWaterDensity.def("__setstate__", &pbUnpickleMessage<WaterDensity>);
	vWaterDensity.def_readwrite("value", &WaterDensity::value);
}