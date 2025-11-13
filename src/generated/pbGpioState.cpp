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

void pbGpioState(py::module &m) {
	auto vGpioState = py::class_<GpioState, Message>(m, "GpioState", "GPIO State");
	vGpioState.def(py::init<>());
	vGpioState.def("__setstate__", &pbUnpickleMessage<GpioState>);
	
	vGpioState.def_property("name",
	    [](const GpioState &x){return ascii_to_unicode_safe(x.name);},
	    [](GpioState &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vGpioState.def_readwrite("value", &GpioState::value);
}