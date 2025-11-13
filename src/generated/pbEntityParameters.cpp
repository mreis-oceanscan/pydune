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

void pbEntityParameters(py::module &m) {
	auto vEntityParameters = py::class_<EntityParameters, Message>(m, "EntityParameters", "EntityParameters");
	vEntityParameters.def(py::init<>());
	vEntityParameters.def("__setstate__", &pbUnpickleMessage<EntityParameters>);
	
	vEntityParameters.def_property("name",
	    [](const EntityParameters &x){return ascii_to_unicode_safe(x.name);},
	    [](EntityParameters &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vEntityParameters.def_readwrite("params", &EntityParameters::params);
}