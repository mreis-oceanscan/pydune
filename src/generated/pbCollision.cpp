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

void pbCollision(py::module &m) {
	auto vCollision = py::class_<Collision, Message>(m, "Collision", "Collision");
	vCollision.def(py::init<>());
	vCollision.def("__setstate__", &pbUnpickleMessage<Collision>);
	vCollision.def_readwrite("value", &Collision::value);
	vCollision.def_readwrite("type", &Collision::type);

	py::enum_<Collision::TypeBits>(vCollision, "TypeBits", "Type", py::arithmetic())
		.value("X", Collision::TypeBits::CD_X)
		.value("Y", Collision::TypeBits::CD_Y)
		.value("Z", Collision::TypeBits::CD_Z)
		.value("IMPACT", Collision::TypeBits::CD_IMPACT);
}