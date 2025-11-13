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

void pbPathPoint(py::module &m) {
	auto vPathPoint = py::class_<PathPoint, Message>(m, "PathPoint", "Path Point");
	vPathPoint.def(py::init<>());
	vPathPoint.def("__setstate__", &pbUnpickleMessage<PathPoint>);
	vPathPoint.def_readwrite("x", &PathPoint::x);
	vPathPoint.def_readwrite("y", &PathPoint::y);
	vPathPoint.def_readwrite("z", &PathPoint::z);
}