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

void pbGpsFix(py::module &m) {
	auto vGpsFix = py::class_<GpsFix, Message>(m, "GpsFix", "GPS Fix");
	vGpsFix.def(py::init<>());
	vGpsFix.def("__setstate__", &pbUnpickleMessage<GpsFix>);
	vGpsFix.def_readwrite("validity", &GpsFix::validity);
	
	vGpsFix.def_property("type",
	    [](const GpsFix &x){return static_cast<GpsFix::TypeEnum>(x.type);},
	    [](GpsFix *x, const uint8_t &y){x->type = y;},
	    "");
	vGpsFix.def_readwrite("utc_year", &GpsFix::utc_year);
	vGpsFix.def_readwrite("utc_month", &GpsFix::utc_month);
	vGpsFix.def_readwrite("utc_day", &GpsFix::utc_day);
	vGpsFix.def_readwrite("utc_time", &GpsFix::utc_time);
	vGpsFix.def_readwrite("lat", &GpsFix::lat);
	vGpsFix.def_readwrite("lon", &GpsFix::lon);
	vGpsFix.def_readwrite("height", &GpsFix::height);
	vGpsFix.def_readwrite("satellites", &GpsFix::satellites);
	vGpsFix.def_readwrite("cog", &GpsFix::cog);
	vGpsFix.def_readwrite("sog", &GpsFix::sog);
	vGpsFix.def_readwrite("hdop", &GpsFix::hdop);
	vGpsFix.def_readwrite("vdop", &GpsFix::vdop);
	vGpsFix.def_readwrite("hacc", &GpsFix::hacc);
	vGpsFix.def_readwrite("vacc", &GpsFix::vacc);

	py::enum_<GpsFix::ValidityBits>(vGpsFix, "ValidityBits", "Validity", py::arithmetic())
		.value("VALID_DATE", GpsFix::ValidityBits::GFV_VALID_DATE)
		.value("VALID_TIME", GpsFix::ValidityBits::GFV_VALID_TIME)
		.value("VALID_POS", GpsFix::ValidityBits::GFV_VALID_POS)
		.value("VALID_COG", GpsFix::ValidityBits::GFV_VALID_COG)
		.value("VALID_SOG", GpsFix::ValidityBits::GFV_VALID_SOG)
		.value("VALID_HACC", GpsFix::ValidityBits::GFV_VALID_HACC)
		.value("VALID_VACC", GpsFix::ValidityBits::GFV_VALID_VACC)
		.value("VALID_HDOP", GpsFix::ValidityBits::GFV_VALID_HDOP)
		.value("VALID_VDOP", GpsFix::ValidityBits::GFV_VALID_VDOP);

	py::enum_<GpsFix::TypeEnum>(vGpsFix, "TypeEnum", "Type")
		.value("STANDALONE", GpsFix::TypeEnum::GFT_STANDALONE)
		.value("DIFFERENTIAL", GpsFix::TypeEnum::GFT_DIFFERENTIAL)
		.value("DEAD_RECKONING", GpsFix::TypeEnum::GFT_DEAD_RECKONING)
		.value("MANUAL_INPUT", GpsFix::TypeEnum::GFT_MANUAL_INPUT)
		.value("SIMULATION", GpsFix::TypeEnum::GFT_SIMULATION);
}