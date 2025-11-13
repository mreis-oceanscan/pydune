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

void pbDesiredVerticalRate(py::module &m) {
	auto vDesiredVerticalRate = py::class_<DesiredVerticalRate, Message>(m, "DesiredVerticalRate", "Desired Vertical Rate");
	vDesiredVerticalRate.def(py::init<>());
	vDesiredVerticalRate.def("__setstate__", &pbUnpickleMessage<DesiredVerticalRate>);
	vDesiredVerticalRate.def_readwrite("value", &DesiredVerticalRate::value);
}