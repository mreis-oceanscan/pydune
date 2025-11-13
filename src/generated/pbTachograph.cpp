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

void pbTachograph(py::module &m) {
	auto vTachograph = py::class_<Tachograph, Message>(m, "Tachograph", "Tachograph");
	vTachograph.def(py::init<>());
	vTachograph.def("__setstate__", &pbUnpickleMessage<Tachograph>);
	vTachograph.def_readwrite("timestamp_last_service", &Tachograph::timestamp_last_service);
	vTachograph.def_readwrite("time_next_service", &Tachograph::time_next_service);
	vTachograph.def_readwrite("time_motor_next_service", &Tachograph::time_motor_next_service);
	vTachograph.def_readwrite("time_idle_ground", &Tachograph::time_idle_ground);
	vTachograph.def_readwrite("time_idle_air", &Tachograph::time_idle_air);
	vTachograph.def_readwrite("time_idle_water", &Tachograph::time_idle_water);
	vTachograph.def_readwrite("time_idle_underwater", &Tachograph::time_idle_underwater);
	vTachograph.def_readwrite("time_idle_unknown", &Tachograph::time_idle_unknown);
	vTachograph.def_readwrite("time_motor_ground", &Tachograph::time_motor_ground);
	vTachograph.def_readwrite("time_motor_air", &Tachograph::time_motor_air);
	vTachograph.def_readwrite("time_motor_water", &Tachograph::time_motor_water);
	vTachograph.def_readwrite("time_motor_underwater", &Tachograph::time_motor_underwater);
	vTachograph.def_readwrite("time_motor_unknown", &Tachograph::time_motor_unknown);
	vTachograph.def_readwrite("rpm_min", &Tachograph::rpm_min);
	vTachograph.def_readwrite("rpm_max", &Tachograph::rpm_max);
	vTachograph.def_readwrite("depth_max", &Tachograph::depth_max);
}