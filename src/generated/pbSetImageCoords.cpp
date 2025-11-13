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

void pbSetImageCoords(py::module &m) {
	auto vSetImageCoords = py::class_<SetImageCoords, Message>(m, "SetImageCoords", "Set Image Coordinates");
	vSetImageCoords.def(py::init<>());
	vSetImageCoords.def("__setstate__", &pbUnpickleMessage<SetImageCoords>);
	vSetImageCoords.def_readwrite("camid", &SetImageCoords::camid);
	vSetImageCoords.def_readwrite("x", &SetImageCoords::x);
	vSetImageCoords.def_readwrite("y", &SetImageCoords::y);
}