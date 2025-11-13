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

void pbAssetReport(py::module &m) {
	auto vAssetReport = py::class_<AssetReport, Message>(m, "AssetReport", "Asset Report ");
	vAssetReport.def(py::init<>());
	vAssetReport.def("__setstate__", &pbUnpickleMessage<AssetReport>);
	
	vAssetReport.def_property("name",
	    [](const AssetReport &x){return ascii_to_unicode_safe(x.name);},
	    [](AssetReport &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vAssetReport.def_readwrite("report_time", &AssetReport::report_time);
	
	vAssetReport.def_property("medium",
	    [](const AssetReport &x){return static_cast<AssetReport::MediumEnum>(x.medium);},
	    [](AssetReport *x, const uint8_t &y){x->medium = y;},
	    "");
	vAssetReport.def_readwrite("lat", &AssetReport::lat);
	vAssetReport.def_readwrite("lon", &AssetReport::lon);
	vAssetReport.def_readwrite("depth", &AssetReport::depth);
	vAssetReport.def_readwrite("alt", &AssetReport::alt);
	vAssetReport.def_readwrite("sog", &AssetReport::sog);
	vAssetReport.def_readwrite("cog", &AssetReport::cog);
	vAssetReport.def_readwrite("msgs", &AssetReport::msgs);

	py::enum_<AssetReport::MediumEnum>(vAssetReport, "MediumEnum", "Medium")
		.value("WIFI", AssetReport::MediumEnum::RM_WIFI)
		.value("SATELLITE", AssetReport::MediumEnum::RM_SATELLITE)
		.value("ACOUSTIC", AssetReport::MediumEnum::RM_ACOUSTIC)
		.value("SMS", AssetReport::MediumEnum::RM_SMS);
}