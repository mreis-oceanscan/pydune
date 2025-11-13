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

void pbGroundVelocity(py::module &m) {
	auto vGroundVelocity = py::class_<GroundVelocity, Message>(m, "GroundVelocity", "Ground Velocity");
	vGroundVelocity.def(py::init<>());
	vGroundVelocity.def("__setstate__", &pbUnpickleMessage<GroundVelocity>);
	vGroundVelocity.def_readwrite("validity", &GroundVelocity::validity);
	vGroundVelocity.def_readwrite("x", &GroundVelocity::x);
	vGroundVelocity.def_readwrite("y", &GroundVelocity::y);
	vGroundVelocity.def_readwrite("z", &GroundVelocity::z);

	py::enum_<GroundVelocity::ValidityBits>(vGroundVelocity, "ValidityBits", "Validity", py::arithmetic())
		.value("VEL_X", GroundVelocity::ValidityBits::VAL_VEL_X)
		.value("VEL_Y", GroundVelocity::ValidityBits::VAL_VEL_Y)
		.value("VEL_Z", GroundVelocity::ValidityBits::VAL_VEL_Z);
}