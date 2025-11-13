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

void pbMapFeature(py::module &m) {
	auto vMapFeature = py::class_<MapFeature, Message>(m, "MapFeature", "Map Feature");
	vMapFeature.def(py::init<>());
	vMapFeature.def("__setstate__", &pbUnpickleMessage<MapFeature>);
	
	vMapFeature.def_property("id",
	    [](const MapFeature &x){return ascii_to_unicode_safe(x.id);},
	    [](MapFeature &x, std::string &s){x.id = s;}, py::return_value_policy::take_ownership);
	
	vMapFeature.def_property("feature_type",
	    [](const MapFeature &x){return static_cast<MapFeature::FeatureTypeEnum>(x.feature_type);},
	    [](MapFeature *x, const uint8_t &y){x->feature_type = y;},
	    "");
	vMapFeature.def_readwrite("rgb_red", &MapFeature::rgb_red);
	vMapFeature.def_readwrite("rgb_green", &MapFeature::rgb_green);
	vMapFeature.def_readwrite("rgb_blue", &MapFeature::rgb_blue);
	vMapFeature.def_readwrite("feature", &MapFeature::feature);

	py::enum_<MapFeature::FeatureTypeEnum>(vMapFeature, "FeaturetypeEnum", "FeatureType")
		.value("POI", MapFeature::FeatureTypeEnum::FTYPE_POI)
		.value("FILLEDPOLY", MapFeature::FeatureTypeEnum::FTYPE_FILLEDPOLY)
		.value("CONTOUREDPOLY", MapFeature::FeatureTypeEnum::FTYPE_CONTOUREDPOLY)
		.value("LINE", MapFeature::FeatureTypeEnum::FTYPE_LINE)
		.value("TRANSPONDER", MapFeature::FeatureTypeEnum::FTYPE_TRANSPONDER)
		.value("STARTLOC", MapFeature::FeatureTypeEnum::FTYPE_STARTLOC)
		.value("HOMEREF", MapFeature::FeatureTypeEnum::FTYPE_HOMEREF);
}