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

void pbLblRangeAcceptance(py::module &m) {
	auto vLblRangeAcceptance = py::class_<LblRangeAcceptance, Message>(m, "LblRangeAcceptance", "LBL Range Acceptance");
	vLblRangeAcceptance.def(py::init<>());
	vLblRangeAcceptance.def("__setstate__", &pbUnpickleMessage<LblRangeAcceptance>);
	vLblRangeAcceptance.def_readwrite("id", &LblRangeAcceptance::id);
	vLblRangeAcceptance.def_readwrite("range", &LblRangeAcceptance::range);
	
	vLblRangeAcceptance.def_property("acceptance",
	    [](const LblRangeAcceptance &x){return static_cast<LblRangeAcceptance::AcceptanceEnum>(x.acceptance);},
	    [](LblRangeAcceptance *x, const uint8_t &y){x->acceptance = y;},
	    "");

	py::enum_<LblRangeAcceptance::AcceptanceEnum>(vLblRangeAcceptance, "AcceptanceEnum", "Acceptance")
		.value("ACCEPTED", LblRangeAcceptance::AcceptanceEnum::RR_ACCEPTED)
		.value("ABOVE_THRESHOLD", LblRangeAcceptance::AcceptanceEnum::RR_ABOVE_THRESHOLD)
		.value("SINGULAR", LblRangeAcceptance::AcceptanceEnum::RR_SINGULAR)
		.value("NO_INFO", LblRangeAcceptance::AcceptanceEnum::RR_NO_INFO)
		.value("AT_SURFACE", LblRangeAcceptance::AcceptanceEnum::RR_AT_SURFACE);
}