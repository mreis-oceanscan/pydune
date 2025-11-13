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

void pbSmsTx(py::module &m) {
	auto vSmsTx = py::class_<SmsTx, Message>(m, "SmsTx", "SMS Transmit");
	vSmsTx.def(py::init<>());
	vSmsTx.def("__setstate__", &pbUnpickleMessage<SmsTx>);
	vSmsTx.def_readwrite("seq", &SmsTx::seq);
	
	vSmsTx.def_property("destination",
	    [](const SmsTx &x){return ascii_to_unicode_safe(x.destination);},
	    [](SmsTx &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	vSmsTx.def_readwrite("timeout", &SmsTx::timeout);
	
	vSmsTx.def_property("data",
	    [](const SmsTx &x){return py::bytes(x.data.data(), x.data.size());},
	    [](SmsTx &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}