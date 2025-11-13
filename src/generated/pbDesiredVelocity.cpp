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

void pbDesiredVelocity(py::module &m) {
	auto vDesiredVelocity = py::class_<DesiredVelocity, Message>(m, "DesiredVelocity", "Desired Velocity");
	vDesiredVelocity.def(py::init<>());
	vDesiredVelocity.def("__setstate__", &pbUnpickleMessage<DesiredVelocity>);
	vDesiredVelocity.def_readwrite("u", &DesiredVelocity::u);
	vDesiredVelocity.def_readwrite("v", &DesiredVelocity::v);
	vDesiredVelocity.def_readwrite("w", &DesiredVelocity::w);
	vDesiredVelocity.def_readwrite("p", &DesiredVelocity::p);
	vDesiredVelocity.def_readwrite("q", &DesiredVelocity::q);
	vDesiredVelocity.def_readwrite("r", &DesiredVelocity::r);
	vDesiredVelocity.def_readwrite("flags", &DesiredVelocity::flags);

	py::enum_<DesiredVelocity::FlagsBits>(vDesiredVelocity, "FlagsBits", "Flags", py::arithmetic())
		.value("SURGE", DesiredVelocity::FlagsBits::FL_SURGE)
		.value("SWAY", DesiredVelocity::FlagsBits::FL_SWAY)
		.value("HEAVE", DesiredVelocity::FlagsBits::FL_HEAVE)
		.value("ROLL", DesiredVelocity::FlagsBits::FL_ROLL)
		.value("PITCH", DesiredVelocity::FlagsBits::FL_PITCH)
		.value("YAW", DesiredVelocity::FlagsBits::FL_YAW);
}