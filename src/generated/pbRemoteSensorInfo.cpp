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

void pbRemoteSensorInfo(py::module &m) {
	auto vRemoteSensorInfo = py::class_<RemoteSensorInfo, Message>(m, "RemoteSensorInfo", "Remote Sensor Info");
	vRemoteSensorInfo.def(py::init<>());
	vRemoteSensorInfo.def("__setstate__", &pbUnpickleMessage<RemoteSensorInfo>);
	
	vRemoteSensorInfo.def_property("id",
	    [](const RemoteSensorInfo &x){return ascii_to_unicode_safe(x.id);},
	    [](RemoteSensorInfo &x, std::string &s){x.id = s;}, py::return_value_policy::take_ownership);
	
	vRemoteSensorInfo.def_property("sensor_class",
	    [](const RemoteSensorInfo &x){return ascii_to_unicode_safe(x.sensor_class);},
	    [](RemoteSensorInfo &x, std::string &s){x.sensor_class = s;}, py::return_value_policy::take_ownership);
	vRemoteSensorInfo.def_readwrite("lat", &RemoteSensorInfo::lat);
	vRemoteSensorInfo.def_readwrite("lon", &RemoteSensorInfo::lon);
	vRemoteSensorInfo.def_readwrite("alt", &RemoteSensorInfo::alt);
	vRemoteSensorInfo.def_readwrite("heading", &RemoteSensorInfo::heading);
	
	vRemoteSensorInfo.def_property("data",
	    [](const RemoteSensorInfo &x){return ascii_to_unicode_safe(x.data);},
	    [](RemoteSensorInfo &x, std::string &s){x.data = s;}, py::return_value_policy::take_ownership);
}