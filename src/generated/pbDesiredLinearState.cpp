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

void pbDesiredLinearState(py::module &m) {
	auto vDesiredLinearState = py::class_<DesiredLinearState, Message>(m, "DesiredLinearState", "Desired Linear State");
	vDesiredLinearState.def(py::init<>());
	vDesiredLinearState.def("__setstate__", &pbUnpickleMessage<DesiredLinearState>);
	vDesiredLinearState.def_readwrite("x", &DesiredLinearState::x);
	vDesiredLinearState.def_readwrite("y", &DesiredLinearState::y);
	vDesiredLinearState.def_readwrite("z", &DesiredLinearState::z);
	vDesiredLinearState.def_readwrite("vx", &DesiredLinearState::vx);
	vDesiredLinearState.def_readwrite("vy", &DesiredLinearState::vy);
	vDesiredLinearState.def_readwrite("vz", &DesiredLinearState::vz);
	vDesiredLinearState.def_readwrite("ax", &DesiredLinearState::ax);
	vDesiredLinearState.def_readwrite("ay", &DesiredLinearState::ay);
	vDesiredLinearState.def_readwrite("az", &DesiredLinearState::az);
	vDesiredLinearState.def_readwrite("flags", &DesiredLinearState::flags);

	py::enum_<DesiredLinearState::FlagsBits>(vDesiredLinearState, "FlagsBits", "Flags", py::arithmetic())
		.value("X", DesiredLinearState::FlagsBits::FL_X)
		.value("Y", DesiredLinearState::FlagsBits::FL_Y)
		.value("Z", DesiredLinearState::FlagsBits::FL_Z)
		.value("VX", DesiredLinearState::FlagsBits::FL_VX)
		.value("VY", DesiredLinearState::FlagsBits::FL_VY)
		.value("VZ", DesiredLinearState::FlagsBits::FL_VZ)
		.value("AX", DesiredLinearState::FlagsBits::FL_AX)
		.value("AY", DesiredLinearState::FlagsBits::FL_AY)
		.value("AZ", DesiredLinearState::FlagsBits::FL_AZ);
}