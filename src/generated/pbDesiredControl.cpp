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

void pbDesiredControl(py::module &m) {
	auto vDesiredControl = py::class_<DesiredControl, Message>(m, "DesiredControl", "Desired Control");
	vDesiredControl.def(py::init<>());
	vDesiredControl.def("__setstate__", &pbUnpickleMessage<DesiredControl>);
	vDesiredControl.def_readwrite("x", &DesiredControl::x);
	vDesiredControl.def_readwrite("y", &DesiredControl::y);
	vDesiredControl.def_readwrite("z", &DesiredControl::z);
	vDesiredControl.def_readwrite("k", &DesiredControl::k);
	vDesiredControl.def_readwrite("m", &DesiredControl::m);
	vDesiredControl.def_readwrite("n", &DesiredControl::n);
	vDesiredControl.def_readwrite("flags", &DesiredControl::flags);

	py::enum_<DesiredControl::FlagsBits>(vDesiredControl, "FlagsBits", "Flags", py::arithmetic())
		.value("X", DesiredControl::FlagsBits::FL_X)
		.value("Y", DesiredControl::FlagsBits::FL_Y)
		.value("Z", DesiredControl::FlagsBits::FL_Z)
		.value("K", DesiredControl::FlagsBits::FL_K)
		.value("M", DesiredControl::FlagsBits::FL_M)
		.value("N", DesiredControl::FlagsBits::FL_N);
}