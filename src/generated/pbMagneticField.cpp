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

void pbMagneticField(py::module &m) {
	auto vMagneticField = py::class_<MagneticField, Message>(m, "MagneticField", "Magnetic Field");
	vMagneticField.def(py::init<>());
	vMagneticField.def("__setstate__", &pbUnpickleMessage<MagneticField>);
	vMagneticField.def_readwrite("time", &MagneticField::time);
	vMagneticField.def_readwrite("x", &MagneticField::x);
	vMagneticField.def_readwrite("y", &MagneticField::y);
	vMagneticField.def_readwrite("z", &MagneticField::z);
}