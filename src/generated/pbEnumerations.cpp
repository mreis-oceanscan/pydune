#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <DUNE/IMC/Enumerations.hpp>
namespace py = pybind11;
using namespace DUNE::IMC;

void pbEnumerations(py::module &m) {
	py::enum_<ControlledMode>(m, "ControlledMode", "Controlled Mode")
		.value("RELINQUISH_HANDOFF_CTL", ControlledMode::CTLMD_RELINQUISH_HANDOFF_CTL)
		.value("REQUEST_CTL", ControlledMode::CTLMD_REQUEST_CTL)
		.value("OVERRIDE_CTL", ControlledMode::CTLMD_OVERRIDE_CTL);
	py::enum_<SpeedUnits>(m, "SpeedUnits", "Speed Units")
		.value("METERS_PS", SpeedUnits::SUNITS_METERS_PS)
		.value("RPM", SpeedUnits::SUNITS_RPM)
		.value("PERCENTAGE", SpeedUnits::SUNITS_PERCENTAGE);
	py::enum_<SystemType>(m, "SystemType", "System Type")
		.value("CCU", SystemType::SYSTEMTYPE_CCU)
		.value("HUMANSENSOR", SystemType::SYSTEMTYPE_HUMANSENSOR)
		.value("UUV", SystemType::SYSTEMTYPE_UUV)
		.value("USV", SystemType::SYSTEMTYPE_USV)
		.value("UAV", SystemType::SYSTEMTYPE_UAV)
		.value("UGV", SystemType::SYSTEMTYPE_UGV)
		.value("STATICSENSOR", SystemType::SYSTEMTYPE_STATICSENSOR)
		.value("MOBILESENSOR", SystemType::SYSTEMTYPE_MOBILESENSOR)
		.value("WSN", SystemType::SYSTEMTYPE_WSN);
	py::enum_<ZUnits>(m, "ZUnits", "Z Units")
		.value("NONE", ZUnits::Z_NONE)
		.value("DEPTH", ZUnits::Z_DEPTH)
		.value("ALTITUDE", ZUnits::Z_ALTITUDE)
		.value("HEIGHT", ZUnits::Z_HEIGHT);
	py::enum_<RSSIUnits>(m, "RSSIUnits", "RSSI Units")
		.value("dB", RSSIUnits::RSSIUNITS_dB)
		.value("PERCENTAGE", RSSIUnits::RSSIUNITS_PERCENTAGE);
	py::enum_<UAVType>(m, "UAVType", "UAV Type")
		.value("FIXEDWING", UAVType::UAVTYPE_FIXEDWING)
		.value("COPTER", UAVType::UAVTYPE_COPTER)
		.value("VTOL", UAVType::UAVTYPE_VTOL);
}
