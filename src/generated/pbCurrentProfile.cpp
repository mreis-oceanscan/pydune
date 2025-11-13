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

void pbCurrentProfile(py::module &m) {
	auto vCurrentProfile = py::class_<CurrentProfile, Message>(m, "CurrentProfile", "Current Profile");
	vCurrentProfile.def(py::init<>());
	vCurrentProfile.def("__setstate__", &pbUnpickleMessage<CurrentProfile>);
	vCurrentProfile.def_readwrite("nbeams", &CurrentProfile::nbeams);
	vCurrentProfile.def_readwrite("ncells", &CurrentProfile::ncells);
	vCurrentProfile.def_readwrite("coord_sys", &CurrentProfile::coord_sys);
	vCurrentProfile.def_readwrite("profile", &CurrentProfile::profile);

	py::enum_<CurrentProfile::CoordinateSystemBits>(vCurrentProfile, "CoordinateSystemBits", "Coordinate System", py::arithmetic())
		.value("XYZ", CurrentProfile::CoordinateSystemBits::UTF_XYZ)
		.value("NED", CurrentProfile::CoordinateSystemBits::UTF_NED)
		.value("BEAMS", CurrentProfile::CoordinateSystemBits::UTF_BEAMS)
		.value("ENU", CurrentProfile::CoordinateSystemBits::UTF_ENU);
}