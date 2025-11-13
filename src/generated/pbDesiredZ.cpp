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

void pbDesiredZ(py::module &m) {
	auto vDesiredZ = py::class_<DesiredZ, ControlCommand>(m, "DesiredZ", "Desired Z");
	vDesiredZ.def(py::init<>());
	vDesiredZ.def("__setstate__", &pbUnpickleMessage<DesiredZ>);
	vDesiredZ.def_readwrite("value", &DesiredZ::value);
	
	vDesiredZ.def_property("z_units",
	    [](const DesiredZ &x){return static_cast<ZUnits>(x.z_units);},
	    [](DesiredZ *x, const uint8_t &y){x->z_units = y;},
	    "");
}