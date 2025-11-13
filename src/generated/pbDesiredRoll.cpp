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

void pbDesiredRoll(py::module &m) {
	auto vDesiredRoll = py::class_<DesiredRoll, ControlCommand>(m, "DesiredRoll", "Desired Roll");
	vDesiredRoll.def(py::init<>());
	vDesiredRoll.def("__setstate__", &pbUnpickleMessage<DesiredRoll>);
	vDesiredRoll.def_readwrite("value", &DesiredRoll::value);
}