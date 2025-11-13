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

void pbSetEntityParameters(py::module &m) {
	auto vSetEntityParameters = py::class_<SetEntityParameters, Message>(m, "SetEntityParameters", "SetEntityParameters");
	vSetEntityParameters.def(py::init<>());
	vSetEntityParameters.def("__setstate__", &pbUnpickleMessage<SetEntityParameters>);
	
	vSetEntityParameters.def_property("name",
	    [](const SetEntityParameters &x){return ascii_to_unicode_safe(x.name);},
	    [](SetEntityParameters &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vSetEntityParameters.def_readwrite("params", &SetEntityParameters::params);
}