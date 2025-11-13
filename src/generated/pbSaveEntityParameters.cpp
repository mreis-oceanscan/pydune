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

void pbSaveEntityParameters(py::module &m) {
	auto vSaveEntityParameters = py::class_<SaveEntityParameters, Message>(m, "SaveEntityParameters", "SaveEntityParameters");
	vSaveEntityParameters.def(py::init<>());
	vSaveEntityParameters.def("__setstate__", &pbUnpickleMessage<SaveEntityParameters>);
	
	vSaveEntityParameters.def_property("name",
	    [](const SaveEntityParameters &x){return ascii_to_unicode_safe(x.name);},
	    [](SaveEntityParameters &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
}