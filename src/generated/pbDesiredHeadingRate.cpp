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

void pbDesiredHeadingRate(py::module &m) {
	auto vDesiredHeadingRate = py::class_<DesiredHeadingRate, Message>(m, "DesiredHeadingRate", "Desired Heading Rate");
	vDesiredHeadingRate.def(py::init<>());
	vDesiredHeadingRate.def("__setstate__", &pbUnpickleMessage<DesiredHeadingRate>);
	vDesiredHeadingRate.def_readwrite("value", &DesiredHeadingRate::value);
}