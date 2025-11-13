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

void pbSadcReadings(py::module &m) {
	auto vSadcReadings = py::class_<SadcReadings, Message>(m, "SadcReadings", "SADC Readings");
	vSadcReadings.def(py::init<>());
	vSadcReadings.def("__setstate__", &pbUnpickleMessage<SadcReadings>);
	vSadcReadings.def_readwrite("channel", &SadcReadings::channel);
	vSadcReadings.def_readwrite("value", &SadcReadings::value);
	
	vSadcReadings.def_property("gain",
	    [](const SadcReadings &x){return static_cast<SadcReadings::GainEnum>(x.gain);},
	    [](SadcReadings *x, const uint8_t &y){x->gain = y;},
	    "");

	py::enum_<SadcReadings::GainEnum>(vSadcReadings, "GainEnum", "Gain")
		.value("X1", SadcReadings::GainEnum::GAIN_X1)
		.value("X10", SadcReadings::GainEnum::GAIN_X10)
		.value("X100", SadcReadings::GainEnum::GAIN_X100);
}