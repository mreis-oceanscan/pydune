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

void pbVehicleMedium(py::module &m) {
	auto vVehicleMedium = py::class_<VehicleMedium, Message>(m, "VehicleMedium", "Vehicle Medium");
	vVehicleMedium.def(py::init<>());
	vVehicleMedium.def("__setstate__", &pbUnpickleMessage<VehicleMedium>);
	
	vVehicleMedium.def_property("medium",
	    [](const VehicleMedium &x){return static_cast<VehicleMedium::MediumEnum>(x.medium);},
	    [](VehicleMedium *x, const uint8_t &y){x->medium = y;},
	    "");

	py::enum_<VehicleMedium::MediumEnum>(vVehicleMedium, "MediumEnum", "Medium")
		.value("GROUND", VehicleMedium::MediumEnum::VM_GROUND)
		.value("AIR", VehicleMedium::MediumEnum::VM_AIR)
		.value("WATER", VehicleMedium::MediumEnum::VM_WATER)
		.value("UNDERWATER", VehicleMedium::MediumEnum::VM_UNDERWATER)
		.value("UNKNOWN", VehicleMedium::MediumEnum::VM_UNKNOWN);
}