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

void pbFuelLevel(py::module &m) {
	auto vFuelLevel = py::class_<FuelLevel, Message>(m, "FuelLevel", "Fuel Level");
	vFuelLevel.def(py::init<>());
	vFuelLevel.def("__setstate__", &pbUnpickleMessage<FuelLevel>);
	vFuelLevel.def_readwrite("value", &FuelLevel::value);
	vFuelLevel.def_readwrite("confidence", &FuelLevel::confidence);
	
	vFuelLevel.def_property("opmodes",
	    [](const FuelLevel &x){return ascii_to_unicode_safe(x.opmodes);},
	    [](FuelLevel &x, std::string &s){x.opmodes = s;}, py::return_value_policy::take_ownership);
}