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

void pbMap(py::module &m) {
	auto vMap = py::class_<Map, Message>(m, "Map", "Map");
	vMap.def(py::init<>());
	vMap.def("__setstate__", &pbUnpickleMessage<Map>);
	
	vMap.def_property("id",
	    [](const Map &x){return ascii_to_unicode_safe(x.id);},
	    [](Map &x, std::string &s){x.id = s;}, py::return_value_policy::take_ownership);
	vMap.def_readwrite("features", &Map::features);
}