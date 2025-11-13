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

void pbGnssHwMon(py::module &m) {
	auto vGnssHwMon = py::class_<GnssHwMon, Message>(m, "GnssHwMon", "GNSS Hardware Monitor");
	vGnssHwMon.def(py::init<>());
	vGnssHwMon.def("__setstate__", &pbUnpickleMessage<GnssHwMon>);
	vGnssHwMon.def_readwrite("jamming_prob", &GnssHwMon::jamming_prob);
	
	vGnssHwMon.def_property("jam_stat",
	    [](const GnssHwMon &x){return static_cast<GnssHwMon::JammingStatusEnum>(x.jam_stat);},
	    [](GnssHwMon *x, const uint8_t &y){x->jam_stat = y;},
	    "");
	vGnssHwMon.def_readwrite("rf_noise", &GnssHwMon::rf_noise);
	
	vGnssHwMon.def_property("ant_stat",
	    [](const GnssHwMon &x){return static_cast<GnssHwMon::AntennaStatusEnum>(x.ant_stat);},
	    [](GnssHwMon *x, const uint8_t &y){x->ant_stat = y;},
	    "");
	
	vGnssHwMon.def_property("ant_pwr",
	    [](const GnssHwMon &x){return static_cast<GnssHwMon::AntennaPowerEnum>(x.ant_pwr);},
	    [](GnssHwMon *x, const uint8_t &y){x->ant_pwr = y;},
	    "");

	py::enum_<GnssHwMon::JammingStatusEnum>(vGnssHwMon, "JammingStatusEnum", "Jamming Status")
		.value("UNKNOWN", GnssHwMon::JammingStatusEnum::JS_UNKNOWN)
		.value("OK", GnssHwMon::JammingStatusEnum::JS_OK)
		.value("WAR", GnssHwMon::JammingStatusEnum::JS_WAR)
		.value("CRIT", GnssHwMon::JammingStatusEnum::JS_CRIT);

	py::enum_<GnssHwMon::AntennaStatusEnum>(vGnssHwMon, "AntennaStatusEnum", "Antenna Status")
		.value("INIT", GnssHwMon::AntennaStatusEnum::AS_INIT)
		.value("UNKNOWN", GnssHwMon::AntennaStatusEnum::AS_UNKNOWN)
		.value("OK", GnssHwMon::AntennaStatusEnum::AS_OK)
		.value("SHORT", GnssHwMon::AntennaStatusEnum::AS_SHORT)
		.value("OPEN", GnssHwMon::AntennaStatusEnum::AS_OPEN);

	py::enum_<GnssHwMon::AntennaPowerEnum>(vGnssHwMon, "AntennaPowerEnum", "Antenna Power")
		.value("OFF", GnssHwMon::AntennaPowerEnum::AP_OFF)
		.value("ON", GnssHwMon::AntennaPowerEnum::AP_ON)
		.value("UNKNOWN", GnssHwMon::AntennaPowerEnum::AP_UNKNOWN);
}