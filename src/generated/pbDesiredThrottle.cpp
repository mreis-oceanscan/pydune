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

void pbDesiredThrottle(py::module &m) {
	auto vDesiredThrottle = py::class_<DesiredThrottle, ControlCommand>(m, "DesiredThrottle", "Desired Throttle");
	vDesiredThrottle.def(py::init<>());
	vDesiredThrottle.def("__setstate__", &pbUnpickleMessage<DesiredThrottle>);
	vDesiredThrottle.def_readwrite("value", &DesiredThrottle::value);
}