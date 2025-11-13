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

void pbMapPoint(py::module &m) {
	auto vMapPoint = py::class_<MapPoint, Message>(m, "MapPoint", "MapPoint");
	vMapPoint.def(py::init<>());
	vMapPoint.def("__setstate__", &pbUnpickleMessage<MapPoint>);
	vMapPoint.def_readwrite("lat", &MapPoint::lat);
	vMapPoint.def_readwrite("lon", &MapPoint::lon);
	vMapPoint.def_readwrite("alt", &MapPoint::alt);
}