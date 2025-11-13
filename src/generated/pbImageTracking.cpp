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

void pbImageTracking(py::module &m) {
	auto vImageTracking = py::class_<ImageTracking, Maneuver>(m, "ImageTracking", "Image Tracking");
	vImageTracking.def(py::init<>());
	vImageTracking.def("__setstate__", &pbUnpickleMessage<ImageTracking>);
}