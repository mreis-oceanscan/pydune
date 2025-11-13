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

void pbGpioStateSet(py::module &m) {
	auto vGpioStateSet = py::class_<GpioStateSet, Message>(m, "GpioStateSet", "Set GPIO State");
	vGpioStateSet.def(py::init<>());
	vGpioStateSet.def("__setstate__", &pbUnpickleMessage<GpioStateSet>);
	
	vGpioStateSet.def_property("name",
	    [](const GpioStateSet &x){return ascii_to_unicode_safe(x.name);},
	    [](GpioStateSet &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vGpioStateSet.def_readwrite("value", &GpioStateSet::value);
}