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

void pbDesiredHeading(py::module &m) {
	auto vDesiredHeading = py::class_<DesiredHeading, ControlCommand>(m, "DesiredHeading", "Desired Heading");
	vDesiredHeading.def(py::init<>());
	vDesiredHeading.def("__setstate__", &pbUnpickleMessage<DesiredHeading>);
	vDesiredHeading.def_readwrite("value", &DesiredHeading::value);
}