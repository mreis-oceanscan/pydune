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

void pbAisInfo(py::module &m) {
	auto vAisInfo = py::class_<AisInfo, Message>(m, "AisInfo", "AIS Info");
	vAisInfo.def(py::init<>());
	vAisInfo.def("__setstate__", &pbUnpickleMessage<AisInfo>);
	
	vAisInfo.def_property("msg_type",
	    [](const AisInfo &x){return ascii_to_unicode_safe(x.msg_type);},
	    [](AisInfo &x, std::string &s){x.msg_type = s;}, py::return_value_policy::take_ownership);
	
	vAisInfo.def_property("sensor_class",
	    [](const AisInfo &x){return ascii_to_unicode_safe(x.sensor_class);},
	    [](AisInfo &x, std::string &s){x.sensor_class = s;}, py::return_value_policy::take_ownership);
	
	vAisInfo.def_property("mmsi",
	    [](const AisInfo &x){return ascii_to_unicode_safe(x.mmsi);},
	    [](AisInfo &x, std::string &s){x.mmsi = s;}, py::return_value_policy::take_ownership);
	
	vAisInfo.def_property("callsign",
	    [](const AisInfo &x){return ascii_to_unicode_safe(x.callsign);},
	    [](AisInfo &x, std::string &s){x.callsign = s;}, py::return_value_policy::take_ownership);
	
	vAisInfo.def_property("name",
	    [](const AisInfo &x){return ascii_to_unicode_safe(x.name);},
	    [](AisInfo &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vAisInfo.def_readwrite("nav_status", &AisInfo::nav_status);
	vAisInfo.def_readwrite("type_and_cargo", &AisInfo::type_and_cargo);
	vAisInfo.def_readwrite("lat", &AisInfo::lat);
	vAisInfo.def_readwrite("lon", &AisInfo::lon);
	vAisInfo.def_readwrite("course", &AisInfo::course);
	vAisInfo.def_readwrite("speed", &AisInfo::speed);
	vAisInfo.def_readwrite("dist", &AisInfo::dist);
	vAisInfo.def_readwrite("a", &AisInfo::a);
	vAisInfo.def_readwrite("b", &AisInfo::b);
	vAisInfo.def_readwrite("c", &AisInfo::c);
	vAisInfo.def_readwrite("d", &AisInfo::d);
	vAisInfo.def_readwrite("draught", &AisInfo::draught);
}