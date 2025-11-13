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

void pbVehicleOperationalLimits(py::module &m) {
	auto vVehicleOperationalLimits = py::class_<VehicleOperationalLimits, Message>(m, "VehicleOperationalLimits", "Vehicle Operational Limits");
	vVehicleOperationalLimits.def(py::init<>());
	vVehicleOperationalLimits.def("__setstate__", &pbUnpickleMessage<VehicleOperationalLimits>);
	
	vVehicleOperationalLimits.def_property("op",
	    [](const VehicleOperationalLimits &x){return static_cast<VehicleOperationalLimits::ActiononthevehicleoperationallimitsEnum>(x.op);},
	    [](VehicleOperationalLimits *x, const uint8_t &y){x->op = y;},
	    "");
	vVehicleOperationalLimits.def_readwrite("speed_min", &VehicleOperationalLimits::speed_min);
	vVehicleOperationalLimits.def_readwrite("speed_max", &VehicleOperationalLimits::speed_max);
	vVehicleOperationalLimits.def_readwrite("long_accel", &VehicleOperationalLimits::long_accel);
	vVehicleOperationalLimits.def_readwrite("alt_max_msl", &VehicleOperationalLimits::alt_max_msl);
	vVehicleOperationalLimits.def_readwrite("dive_fraction_max", &VehicleOperationalLimits::dive_fraction_max);
	vVehicleOperationalLimits.def_readwrite("climb_fraction_max", &VehicleOperationalLimits::climb_fraction_max);
	vVehicleOperationalLimits.def_readwrite("bank_max", &VehicleOperationalLimits::bank_max);
	vVehicleOperationalLimits.def_readwrite("p_max", &VehicleOperationalLimits::p_max);
	vVehicleOperationalLimits.def_readwrite("pitch_min", &VehicleOperationalLimits::pitch_min);
	vVehicleOperationalLimits.def_readwrite("pitch_max", &VehicleOperationalLimits::pitch_max);
	vVehicleOperationalLimits.def_readwrite("q_max", &VehicleOperationalLimits::q_max);
	vVehicleOperationalLimits.def_readwrite("g_min", &VehicleOperationalLimits::g_min);
	vVehicleOperationalLimits.def_readwrite("g_max", &VehicleOperationalLimits::g_max);
	vVehicleOperationalLimits.def_readwrite("g_lat_max", &VehicleOperationalLimits::g_lat_max);
	vVehicleOperationalLimits.def_readwrite("rpm_min", &VehicleOperationalLimits::rpm_min);
	vVehicleOperationalLimits.def_readwrite("rpm_max", &VehicleOperationalLimits::rpm_max);
	vVehicleOperationalLimits.def_readwrite("rpm_rate_max", &VehicleOperationalLimits::rpm_rate_max);

	py::enum_<VehicleOperationalLimits::ActiononthevehicleoperationallimitsEnum>(vVehicleOperationalLimits, "ActionOnTheVehicleOperationalLimitsEnum", "Action on the vehicle operational limits")
		.value("REQUEST", VehicleOperationalLimits::ActiononthevehicleoperationallimitsEnum::OP_REQUEST)
		.value("SET", VehicleOperationalLimits::ActiononthevehicleoperationallimitsEnum::OP_SET)
		.value("REPORT", VehicleOperationalLimits::ActiononthevehicleoperationallimitsEnum::OP_REPORT);
}