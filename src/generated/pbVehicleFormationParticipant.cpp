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

void pbVehicleFormationParticipant(py::module &m) {
	auto vVehicleFormationParticipant = py::class_<VehicleFormationParticipant, Message>(m, "VehicleFormationParticipant", "Vehicle Formation Participant");
	vVehicleFormationParticipant.def(py::init<>());
	vVehicleFormationParticipant.def("__setstate__", &pbUnpickleMessage<VehicleFormationParticipant>);
	vVehicleFormationParticipant.def_readwrite("vid", &VehicleFormationParticipant::vid);
	vVehicleFormationParticipant.def_readwrite("off_x", &VehicleFormationParticipant::off_x);
	vVehicleFormationParticipant.def_readwrite("off_y", &VehicleFormationParticipant::off_y);
	vVehicleFormationParticipant.def_readwrite("off_z", &VehicleFormationParticipant::off_z);
}