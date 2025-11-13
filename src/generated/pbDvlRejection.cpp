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

void pbDvlRejection(py::module &m) {
	auto vDvlRejection = py::class_<DvlRejection, Message>(m, "DvlRejection", "DVL Rejection");
	vDvlRejection.def(py::init<>());
	vDvlRejection.def("__setstate__", &pbUnpickleMessage<DvlRejection>);
	vDvlRejection.def_readwrite("type", &DvlRejection::type);
	
	vDvlRejection.def_property("reason",
	    [](const DvlRejection &x){return static_cast<DvlRejection::ReasonEnum>(x.reason);},
	    [](DvlRejection *x, const uint8_t &y){x->reason = y;},
	    "");
	vDvlRejection.def_readwrite("value", &DvlRejection::value);
	vDvlRejection.def_readwrite("timestep", &DvlRejection::timestep);

	py::enum_<DvlRejection::TypeofvelocityBits>(vDvlRejection, "TypeOfVelocityBits", "Type of velocity", py::arithmetic())
		.value("GV", DvlRejection::TypeofvelocityBits::TYPE_GV)
		.value("WV", DvlRejection::TypeofvelocityBits::TYPE_WV);

	py::enum_<DvlRejection::ReasonEnum>(vDvlRejection, "ReasonEnum", "Reason")
		.value("INNOV_THRESHOLD_X", DvlRejection::ReasonEnum::RR_INNOV_THRESHOLD_X)
		.value("INNOV_THRESHOLD_Y", DvlRejection::ReasonEnum::RR_INNOV_THRESHOLD_Y)
		.value("ABS_THRESHOLD_X", DvlRejection::ReasonEnum::RR_ABS_THRESHOLD_X)
		.value("ABS_THRESHOLD_Y", DvlRejection::ReasonEnum::RR_ABS_THRESHOLD_Y);
}