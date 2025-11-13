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

void pbEulerAngles(py::module &m) {
	auto vEulerAngles = py::class_<EulerAngles, Message>(m, "EulerAngles", "Euler Angles");
	vEulerAngles.def(py::init<>());
	vEulerAngles.def("__setstate__", &pbUnpickleMessage<EulerAngles>);
	vEulerAngles.def_readwrite("time", &EulerAngles::time);
	vEulerAngles.def_readwrite("phi", &EulerAngles::phi);
	vEulerAngles.def_readwrite("theta", &EulerAngles::theta);
	vEulerAngles.def_readwrite("psi", &EulerAngles::psi);
	vEulerAngles.def_readwrite("psi_magnetic", &EulerAngles::psi_magnetic);
}