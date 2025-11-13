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

void pbSmsRx(py::module &m) {
	auto vSmsRx = py::class_<SmsRx, Message>(m, "SmsRx", "SMS Receive");
	vSmsRx.def(py::init<>());
	vSmsRx.def("__setstate__", &pbUnpickleMessage<SmsRx>);
	
	vSmsRx.def_property("source",
	    [](const SmsRx &x){return ascii_to_unicode_safe(x.source);},
	    [](SmsRx &x, std::string &s){x.source = s;}, py::return_value_policy::take_ownership);
	
	vSmsRx.def_property("data",
	    [](const SmsRx &x){return py::bytes(x.data.data(), x.data.size());},
	    [](SmsRx &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}