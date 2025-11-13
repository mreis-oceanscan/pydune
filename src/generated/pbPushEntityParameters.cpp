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

void pbPushEntityParameters(py::module &m) {
	auto vPushEntityParameters = py::class_<PushEntityParameters, Message>(m, "PushEntityParameters", "Push Entity Parameters");
	vPushEntityParameters.def(py::init<>());
	vPushEntityParameters.def("__setstate__", &pbUnpickleMessage<PushEntityParameters>);
	
	vPushEntityParameters.def_property("name",
	    [](const PushEntityParameters &x){return ascii_to_unicode_safe(x.name);},
	    [](PushEntityParameters &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
}