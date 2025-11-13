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

void pbLblBeaconExtended(py::module &m) {
	auto vLblBeaconExtended = py::class_<LblBeaconExtended, Message>(m, "LblBeaconExtended", "LBL Beacon Configuration Extended");
	vLblBeaconExtended.def(py::init<>());
	vLblBeaconExtended.def("__setstate__", &pbUnpickleMessage<LblBeaconExtended>);
	
	vLblBeaconExtended.def_property("beacon",
	    [](const LblBeaconExtended &x){return ascii_to_unicode_safe(x.beacon);},
	    [](LblBeaconExtended &x, std::string &s){x.beacon = s;}, py::return_value_policy::take_ownership);
	vLblBeaconExtended.def_readwrite("lat", &LblBeaconExtended::lat);
	vLblBeaconExtended.def_readwrite("lon", &LblBeaconExtended::lon);
	vLblBeaconExtended.def_readwrite("depth", &LblBeaconExtended::depth);
	vLblBeaconExtended.def_readwrite("query_channel", &LblBeaconExtended::query_channel);
	vLblBeaconExtended.def_readwrite("reply_channel", &LblBeaconExtended::reply_channel);
	vLblBeaconExtended.def_readwrite("transponder_delay", &LblBeaconExtended::transponder_delay);
	vLblBeaconExtended.def_readwrite("ctime", &LblBeaconExtended::ctime);
	vLblBeaconExtended.def_readwrite("ttl", &LblBeaconExtended::ttl);
	vLblBeaconExtended.def_readwrite("vx", &LblBeaconExtended::vx);
	vLblBeaconExtended.def_readwrite("vy", &LblBeaconExtended::vy);
	vLblBeaconExtended.def_readwrite("vz", &LblBeaconExtended::vz);
}