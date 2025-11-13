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

void pbThrottle(py::module &m) {
	auto vThrottle = py::class_<Throttle, Message>(m, "Throttle", "Throttle");
	vThrottle.def(py::init<>());
	vThrottle.def("__setstate__", &pbUnpickleMessage<Throttle>);
	vThrottle.def_readwrite("value", &Throttle::value);
}