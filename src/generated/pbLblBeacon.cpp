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

void pbLblBeacon(py::module &m) {
	auto vLblBeacon = py::class_<LblBeacon, Message>(m, "LblBeacon", "LBL Beacon Configuration");
	vLblBeacon.def(py::init<>());
	vLblBeacon.def("__setstate__", &pbUnpickleMessage<LblBeacon>);
	
	vLblBeacon.def_property("beacon",
	    [](const LblBeacon &x){return ascii_to_unicode_safe(x.beacon);},
	    [](LblBeacon &x, std::string &s){x.beacon = s;}, py::return_value_policy::take_ownership);
	vLblBeacon.def_readwrite("lat", &LblBeacon::lat);
	vLblBeacon.def_readwrite("lon", &LblBeacon::lon);
	vLblBeacon.def_readwrite("depth", &LblBeacon::depth);
	vLblBeacon.def_readwrite("query_channel", &LblBeacon::query_channel);
	vLblBeacon.def_readwrite("reply_channel", &LblBeacon::reply_channel);
	vLblBeacon.def_readwrite("transponder_delay", &LblBeacon::transponder_delay);
}