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

void pbWaterVelocity(py::module &m) {
	auto vWaterVelocity = py::class_<WaterVelocity, Message>(m, "WaterVelocity", "Water Velocity");
	vWaterVelocity.def(py::init<>());
	vWaterVelocity.def("__setstate__", &pbUnpickleMessage<WaterVelocity>);
	vWaterVelocity.def_readwrite("validity", &WaterVelocity::validity);
	vWaterVelocity.def_readwrite("x", &WaterVelocity::x);
	vWaterVelocity.def_readwrite("y", &WaterVelocity::y);
	vWaterVelocity.def_readwrite("z", &WaterVelocity::z);

	py::enum_<WaterVelocity::ValidityBits>(vWaterVelocity, "ValidityBits", "Validity", py::arithmetic())
		.value("VEL_X", WaterVelocity::ValidityBits::VAL_VEL_X)
		.value("VEL_Y", WaterVelocity::ValidityBits::VAL_VEL_Y)
		.value("VEL_Z", WaterVelocity::ValidityBits::VAL_VEL_Z);
}