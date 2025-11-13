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

void pbTrajectoryPoint(py::module &m) {
	auto vTrajectoryPoint = py::class_<TrajectoryPoint, Message>(m, "TrajectoryPoint", "Trajectory Point");
	vTrajectoryPoint.def(py::init<>());
	vTrajectoryPoint.def("__setstate__", &pbUnpickleMessage<TrajectoryPoint>);
	vTrajectoryPoint.def_readwrite("x", &TrajectoryPoint::x);
	vTrajectoryPoint.def_readwrite("y", &TrajectoryPoint::y);
	vTrajectoryPoint.def_readwrite("z", &TrajectoryPoint::z);
	vTrajectoryPoint.def_readwrite("t", &TrajectoryPoint::t);
}