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

void pbENCAwareness(py::module &m) {
	auto vENCAwareness = py::class_<ENCAwareness, Message>(m, "ENCAwareness", "ENC Awareness");
	vENCAwareness.def(py::init<>());
	vENCAwareness.def("__setstate__", &pbUnpickleMessage<ENCAwareness>);
	
	vENCAwareness.def_property("depth_at_loc",
	    [](const ENCAwareness &x){return ascii_to_unicode_safe(x.depth_at_loc);},
	    [](ENCAwareness &x, std::string &s){x.depth_at_loc = s;}, py::return_value_policy::take_ownership);
	
	vENCAwareness.def_property("danger",
	    [](const ENCAwareness &x){return ascii_to_unicode_safe(x.danger);},
	    [](ENCAwareness &x, std::string &s){x.danger = s;}, py::return_value_policy::take_ownership);
}