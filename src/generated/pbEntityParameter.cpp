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

void pbEntityParameter(py::module &m) {
	auto vEntityParameter = py::class_<EntityParameter, Message>(m, "EntityParameter", "EntityParameter");
	vEntityParameter.def(py::init<>());
	vEntityParameter.def("__setstate__", &pbUnpickleMessage<EntityParameter>);
	
	vEntityParameter.def_property("name",
	    [](const EntityParameter &x){return ascii_to_unicode_safe(x.name);},
	    [](EntityParameter &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vEntityParameter.def_property("value",
	    [](const EntityParameter &x){return ascii_to_unicode_safe(x.value);},
	    [](EntityParameter &x, std::string &s){x.value = s;}, py::return_value_policy::take_ownership);
}