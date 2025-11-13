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

void pbCommand(py::module &m) {
	auto vCommand = py::class_<Command, Message>(m, "Command", "Command To Follow");
	vCommand.def(py::init<>());
	vCommand.def("__setstate__", &pbUnpickleMessage<Command>);
	vCommand.def_readwrite("flags", &Command::flags);
	vCommand.def_readwrite("speed", &Command::speed);
	vCommand.def_readwrite("z", &Command::z);
	vCommand.def_readwrite("heading", &Command::heading);

	py::enum_<Command::FlagsBits>(vCommand, "FlagsBits", "Flags", py::arithmetic())
		.value("SPEED_METERS_PS", Command::FlagsBits::FLAG_SPEED_METERS_PS)
		.value("SPEED_RPM", Command::FlagsBits::FLAG_SPEED_RPM)
		.value("DEPTH", Command::FlagsBits::FLAG_DEPTH)
		.value("ALTITUDE", Command::FlagsBits::FLAG_ALTITUDE)
		.value("HEADING", Command::FlagsBits::FLAG_HEADING)
		.value("HEADING_RATE", Command::FlagsBits::FLAG_HEADING_RATE)
		.value("MANDONE", Command::FlagsBits::FLAG_MANDONE);
}