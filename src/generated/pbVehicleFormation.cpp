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

void pbVehicleFormation(py::module &m) {
	auto vVehicleFormation = py::class_<VehicleFormation, Maneuver>(m, "VehicleFormation", "Vehicle Formation");
	vVehicleFormation.def(py::init<>());
	vVehicleFormation.def("__setstate__", &pbUnpickleMessage<VehicleFormation>);
	vVehicleFormation.def_readwrite("lat", &VehicleFormation::lat);
	vVehicleFormation.def_readwrite("lon", &VehicleFormation::lon);
	vVehicleFormation.def_readwrite("z", &VehicleFormation::z);
	
	vVehicleFormation.def_property("z_units",
	    [](const VehicleFormation &x){return static_cast<ZUnits>(x.z_units);},
	    [](VehicleFormation *x, const uint8_t &y){x->z_units = y;},
	    "");
	vVehicleFormation.def_readwrite("speed", &VehicleFormation::speed);
	
	vVehicleFormation.def_property("speed_units",
	    [](const VehicleFormation &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](VehicleFormation *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vVehicleFormation.def_readwrite("points", &VehicleFormation::points);
	vVehicleFormation.def_readwrite("participants", &VehicleFormation::participants);
	vVehicleFormation.def_readwrite("start_time", &VehicleFormation::start_time);
	
	vVehicleFormation.def_property("custom",
	    [](const VehicleFormation &x){return ascii_to_unicode_safe(x.custom);},
	    [](VehicleFormation &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}