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

void pbGetImageCoords(py::module &m) {
	auto vGetImageCoords = py::class_<GetImageCoords, Message>(m, "GetImageCoords", "Get Image Coordinates");
	vGetImageCoords.def(py::init<>());
	vGetImageCoords.def("__setstate__", &pbUnpickleMessage<GetImageCoords>);
	vGetImageCoords.def_readwrite("camid", &GetImageCoords::camid);
	vGetImageCoords.def_readwrite("x", &GetImageCoords::x);
	vGetImageCoords.def_readwrite("y", &GetImageCoords::y);
}