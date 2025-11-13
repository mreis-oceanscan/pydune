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

void pbQueryEntityParameters(py::module &m) {
	auto vQueryEntityParameters = py::class_<QueryEntityParameters, Message>(m, "QueryEntityParameters", "QueryEntityParameters");
	vQueryEntityParameters.def(py::init<>());
	vQueryEntityParameters.def("__setstate__", &pbUnpickleMessage<QueryEntityParameters>);
	
	vQueryEntityParameters.def_property("name",
	    [](const QueryEntityParameters &x){return ascii_to_unicode_safe(x.name);},
	    [](QueryEntityParameters &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vQueryEntityParameters.def_property("visibility",
	    [](const QueryEntityParameters &x){return ascii_to_unicode_safe(x.visibility);},
	    [](QueryEntityParameters &x, std::string &s){x.visibility = s;}, py::return_value_policy::take_ownership);
	
	vQueryEntityParameters.def_property("scope",
	    [](const QueryEntityParameters &x){return ascii_to_unicode_safe(x.scope);},
	    [](QueryEntityParameters &x, std::string &s){x.scope = s;}, py::return_value_policy::take_ownership);
}