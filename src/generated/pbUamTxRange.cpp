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

void pbUamTxRange(py::module &m) {
	auto vUamTxRange = py::class_<UamTxRange, Message>(m, "UamTxRange", "UamTxRange");
	vUamTxRange.def(py::init<>());
	vUamTxRange.def("__setstate__", &pbUnpickleMessage<UamTxRange>);
	vUamTxRange.def_readwrite("seq", &UamTxRange::seq);
	
	vUamTxRange.def_property("sys_dst",
	    [](const UamTxRange &x){return ascii_to_unicode_safe(x.sys_dst);},
	    [](UamTxRange &x, std::string &s){x.sys_dst = s;}, py::return_value_policy::take_ownership);
	vUamTxRange.def_readwrite("timeout", &UamTxRange::timeout);
}