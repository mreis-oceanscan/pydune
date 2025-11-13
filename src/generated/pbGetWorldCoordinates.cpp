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

void pbGetWorldCoordinates(py::module &m) {
	auto vGetWorldCoordinates = py::class_<GetWorldCoordinates, Message>(m, "GetWorldCoordinates", "Get World Coordinates");
	vGetWorldCoordinates.def(py::init<>());
	vGetWorldCoordinates.def("__setstate__", &pbUnpickleMessage<GetWorldCoordinates>);
	
	vGetWorldCoordinates.def_property("tracking",
	    [](const GetWorldCoordinates &x){return static_cast<Boolean>(x.tracking);},
	    [](GetWorldCoordinates *x, const uint8_t &y){x->tracking = y;},
	    "");
	vGetWorldCoordinates.def_readwrite("lat", &GetWorldCoordinates::lat);
	vGetWorldCoordinates.def_readwrite("lon", &GetWorldCoordinates::lon);
	vGetWorldCoordinates.def_readwrite("x", &GetWorldCoordinates::x);
	vGetWorldCoordinates.def_readwrite("y", &GetWorldCoordinates::y);
	vGetWorldCoordinates.def_readwrite("z", &GetWorldCoordinates::z);
}