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

void pbWifiNetwork(py::module &m) {
	auto vWifiNetwork = py::class_<WifiNetwork, Message>(m, "WifiNetwork", "WiFi Network");
	vWifiNetwork.def(py::init<>());
	vWifiNetwork.def("__setstate__", &pbUnpickleMessage<WifiNetwork>);
	
	vWifiNetwork.def_property("essid",
	    [](const WifiNetwork &x){return ascii_to_unicode_safe(x.essid);},
	    [](WifiNetwork &x, std::string &s){x.essid = s;}, py::return_value_policy::take_ownership);
	
	vWifiNetwork.def_property("mac",
	    [](const WifiNetwork &x){return ascii_to_unicode_safe(x.mac);},
	    [](WifiNetwork &x, std::string &s){x.mac = s;}, py::return_value_policy::take_ownership);
	vWifiNetwork.def_readwrite("signal", &WifiNetwork::signal);
	vWifiNetwork.def_readwrite("noise", &WifiNetwork::noise);
	vWifiNetwork.def_readwrite("ccq", &WifiNetwork::ccq);
	vWifiNetwork.def_readwrite("channel", &WifiNetwork::channel);
	vWifiNetwork.def_readwrite("freq", &WifiNetwork::freq);
	
	vWifiNetwork.def_property("security",
	    [](const WifiNetwork &x){return ascii_to_unicode_safe(x.security);},
	    [](WifiNetwork &x, std::string &s){x.security = s;}, py::return_value_policy::take_ownership);
}