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

void pbUamRxRange(py::module &m) {
	auto vUamRxRange = py::class_<UamRxRange, Message>(m, "UamRxRange", "UamRxRange");
	vUamRxRange.def(py::init<>());
	vUamRxRange.def("__setstate__", &pbUnpickleMessage<UamRxRange>);
	vUamRxRange.def_readwrite("seq", &UamRxRange::seq);
	
	vUamRxRange.def_property("sys",
	    [](const UamRxRange &x){return ascii_to_unicode_safe(x.sys);},
	    [](UamRxRange &x, std::string &s){x.sys = s;}, py::return_value_policy::take_ownership);
	vUamRxRange.def_readwrite("value", &UamRxRange::value);
}