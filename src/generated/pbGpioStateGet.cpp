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

void pbGpioStateGet(py::module &m) {
	auto vGpioStateGet = py::class_<GpioStateGet, Message>(m, "GpioStateGet", "Get GPIO State");
	vGpioStateGet.def(py::init<>());
	vGpioStateGet.def("__setstate__", &pbUnpickleMessage<GpioStateGet>);
	
	vGpioStateGet.def_property("name",
	    [](const GpioStateGet &x){return ascii_to_unicode_safe(x.name);},
	    [](GpioStateGet &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
}