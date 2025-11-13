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

void pbPolygonVertex(py::module &m) {
	auto vPolygonVertex = py::class_<PolygonVertex, Message>(m, "PolygonVertex", "Polygon Vertex");
	vPolygonVertex.def(py::init<>());
	vPolygonVertex.def("__setstate__", &pbUnpickleMessage<PolygonVertex>);
	vPolygonVertex.def_readwrite("lat", &PolygonVertex::lat);
	vPolygonVertex.def_readwrite("lon", &PolygonVertex::lon);
}