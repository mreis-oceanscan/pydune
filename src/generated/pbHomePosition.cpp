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

void pbHomePosition(py::module &m) {
	auto vHomePosition = py::class_<HomePosition, Message>(m, "HomePosition", "Home Position");
	vHomePosition.def(py::init<>());
	vHomePosition.def("__setstate__", &pbUnpickleMessage<HomePosition>);
	
	vHomePosition.def_property("op",
	    [](const HomePosition &x){return static_cast<HomePosition::ActiononthevehiclehomepositionEnum>(x.op);},
	    [](HomePosition *x, const uint8_t &y){x->op = y;},
	    "");
	vHomePosition.def_readwrite("lat", &HomePosition::lat);
	vHomePosition.def_readwrite("lon", &HomePosition::lon);
	vHomePosition.def_readwrite("height", &HomePosition::height);
	vHomePosition.def_readwrite("depth", &HomePosition::depth);
	vHomePosition.def_readwrite("alt", &HomePosition::alt);

	py::enum_<HomePosition::ActiononthevehiclehomepositionEnum>(vHomePosition, "ActionOnTheVehicleHomePositionEnum", "Action on the vehicle home position")
		.value("SET", HomePosition::ActiononthevehiclehomepositionEnum::OP_SET)
		.value("REPORT", HomePosition::ActiononthevehiclehomepositionEnum::OP_REPORT);
}