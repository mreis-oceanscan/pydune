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

void pbPopEntityParameters(py::module &m) {
	auto vPopEntityParameters = py::class_<PopEntityParameters, Message>(m, "PopEntityParameters", "Pop Entity Parameters");
	vPopEntityParameters.def(py::init<>());
	vPopEntityParameters.def("__setstate__", &pbUnpickleMessage<PopEntityParameters>);
	
	vPopEntityParameters.def_property("name",
	    [](const PopEntityParameters &x){return ascii_to_unicode_safe(x.name);},
	    [](PopEntityParameters &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
}