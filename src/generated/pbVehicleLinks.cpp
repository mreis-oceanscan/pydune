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

void pbVehicleLinks(py::module &m) {
	auto vVehicleLinks = py::class_<VehicleLinks, Message>(m, "VehicleLinks", "Vehicle Links");
	vVehicleLinks.def(py::init<>());
	vVehicleLinks.def("__setstate__", &pbUnpickleMessage<VehicleLinks>);
	
	vVehicleLinks.def_property("localname",
	    [](const VehicleLinks &x){return ascii_to_unicode_safe(x.localname);},
	    [](VehicleLinks &x, std::string &s){x.localname = s;}, py::return_value_policy::take_ownership);
	vVehicleLinks.def_readwrite("links", &VehicleLinks::links);
}