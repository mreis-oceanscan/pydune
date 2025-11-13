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

void pbGpsFixRejection(py::module &m) {
	auto vGpsFixRejection = py::class_<GpsFixRejection, Message>(m, "GpsFixRejection", "GPS Fix Rejection");
	vGpsFixRejection.def(py::init<>());
	vGpsFixRejection.def("__setstate__", &pbUnpickleMessage<GpsFixRejection>);
	vGpsFixRejection.def_readwrite("utc_time", &GpsFixRejection::utc_time);
	
	vGpsFixRejection.def_property("reason",
	    [](const GpsFixRejection &x){return static_cast<GpsFixRejection::ReasonEnum>(x.reason);},
	    [](GpsFixRejection *x, const uint8_t &y){x->reason = y;},
	    "");

	py::enum_<GpsFixRejection::ReasonEnum>(vGpsFixRejection, "ReasonEnum", "Reason")
		.value("ABOVE_THRESHOLD", GpsFixRejection::ReasonEnum::RR_ABOVE_THRESHOLD)
		.value("INVALID", GpsFixRejection::ReasonEnum::RR_INVALID)
		.value("ABOVE_MAX_HDOP", GpsFixRejection::ReasonEnum::RR_ABOVE_MAX_HDOP)
		.value("ABOVE_MAX_HACC", GpsFixRejection::ReasonEnum::RR_ABOVE_MAX_HACC)
		.value("LOST_VAL_BIT", GpsFixRejection::ReasonEnum::RR_LOST_VAL_BIT);
}