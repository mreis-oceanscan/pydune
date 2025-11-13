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

void pbWifiStats(py::module &m) {
	auto vWifiStats = py::class_<WifiStats, Message>(m, "WifiStats", "WiFi Statistics");
	vWifiStats.def(py::init<>());
	vWifiStats.def("__setstate__", &pbUnpickleMessage<WifiStats>);
	
	vWifiStats.def_property("mac",
	    [](const WifiStats &x){return ascii_to_unicode_safe(x.mac);},
	    [](WifiStats &x, std::string &s){x.mac = s;}, py::return_value_policy::take_ownership);
	
	vWifiStats.def_property("ip",
	    [](const WifiStats &x){return ascii_to_unicode_safe(x.ip);},
	    [](WifiStats &x, std::string &s){x.ip = s;}, py::return_value_policy::take_ownership);
	vWifiStats.def_readwrite("ccq", &WifiStats::ccq);
	vWifiStats.def_readwrite("noise_floor", &WifiStats::noise_floor);
	vWifiStats.def_readwrite("signal", &WifiStats::signal);
	vWifiStats.def_readwrite("rssi", &WifiStats::rssi);
	vWifiStats.def_readwrite("rx_rate", &WifiStats::rx_rate);
	vWifiStats.def_readwrite("tx_rate", &WifiStats::tx_rate);
	vWifiStats.def_readwrite("tx_latency", &WifiStats::tx_latency);
	vWifiStats.def_readwrite("tx_power", &WifiStats::tx_power);
	vWifiStats.def_readwrite("rx_count", &WifiStats::rx_count);
	vWifiStats.def_readwrite("tx_count", &WifiStats::tx_count);
	vWifiStats.def_readwrite("distance", &WifiStats::distance);
}