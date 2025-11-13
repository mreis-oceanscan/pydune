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

void pbGpsFixRtk(py::module &m) {
	auto vGpsFixRtk = py::class_<GpsFixRtk, Message>(m, "GpsFixRtk", "GPS Fix RTK");
	vGpsFixRtk.def(py::init<>());
	vGpsFixRtk.def("__setstate__", &pbUnpickleMessage<GpsFixRtk>);
	vGpsFixRtk.def_readwrite("validity", &GpsFixRtk::validity);
	
	vGpsFixRtk.def_property("type",
	    [](const GpsFixRtk &x){return static_cast<GpsFixRtk::TypeEnum>(x.type);},
	    [](GpsFixRtk *x, const uint8_t &y){x->type = y;},
	    "");
	vGpsFixRtk.def_readwrite("tow", &GpsFixRtk::tow);
	vGpsFixRtk.def_readwrite("base_lat", &GpsFixRtk::base_lat);
	vGpsFixRtk.def_readwrite("base_lon", &GpsFixRtk::base_lon);
	vGpsFixRtk.def_readwrite("base_height", &GpsFixRtk::base_height);
	vGpsFixRtk.def_readwrite("n", &GpsFixRtk::n);
	vGpsFixRtk.def_readwrite("e", &GpsFixRtk::e);
	vGpsFixRtk.def_readwrite("d", &GpsFixRtk::d);
	vGpsFixRtk.def_readwrite("v_n", &GpsFixRtk::v_n);
	vGpsFixRtk.def_readwrite("v_e", &GpsFixRtk::v_e);
	vGpsFixRtk.def_readwrite("v_d", &GpsFixRtk::v_d);
	vGpsFixRtk.def_readwrite("satellites", &GpsFixRtk::satellites);
	vGpsFixRtk.def_readwrite("iar_hyp", &GpsFixRtk::iar_hyp);
	vGpsFixRtk.def_readwrite("iar_ratio", &GpsFixRtk::iar_ratio);

	py::enum_<GpsFixRtk::ValidityBits>(vGpsFixRtk, "ValidityBits", "Validity", py::arithmetic())
		.value("VALID_TIME", GpsFixRtk::ValidityBits::RFV_VALID_TIME)
		.value("VALID_BASE", GpsFixRtk::ValidityBits::RFV_VALID_BASE)
		.value("VALID_POS", GpsFixRtk::ValidityBits::RFV_VALID_POS)
		.value("VALID_VEL", GpsFixRtk::ValidityBits::RFV_VALID_VEL);

	py::enum_<GpsFixRtk::TypeEnum>(vGpsFixRtk, "TypeEnum", "Type")
		.value("NONE", GpsFixRtk::TypeEnum::RTK_NONE)
		.value("OBS", GpsFixRtk::TypeEnum::RTK_OBS)
		.value("FLOAT", GpsFixRtk::TypeEnum::RTK_FLOAT)
		.value("FIXED", GpsFixRtk::TypeEnum::RTK_FIXED);
}