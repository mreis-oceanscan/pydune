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

void pbBDI(py::module &m) {
	auto vBDI = py::class_<BDI, Message>(m, "BDI", "Battery Detailed Info");
	vBDI.def(py::init<>());
	vBDI.def("__setstate__", &pbUnpickleMessage<BDI>);
	vBDI.def_readwrite("soh", &BDI::soh);
	
	vBDI.def_property("is_fd",
	    [](const BDI &x){return static_cast<BDI::IsFullyDischargedEnum>(x.is_fd);},
	    [](BDI *x, const uint8_t &y){x->is_fd = y;},
	    "");
	
	vBDI.def_property("is_fc",
	    [](const BDI &x){return static_cast<BDI::IsFullyChargedEnum>(x.is_fc);},
	    [](BDI *x, const uint8_t &y){x->is_fc = y;},
	    "");
	
	vBDI.def_property("rest",
	    [](const BDI &x){return static_cast<BDI::RESTEnum>(x.rest);},
	    [](BDI *x, const uint8_t &y){x->rest = y;},
	    "");
	
	vBDI.def_property("vdq",
	    [](const BDI &x){return static_cast<BDI::VDQEnum>(x.vdq);},
	    [](BDI *x, const uint8_t &y){x->vdq = y;},
	    "");
	vBDI.def_readwrite("cycle_count", &BDI::cycle_count);
	vBDI.def_readwrite("full_capacity", &BDI::full_capacity);
	vBDI.def_readwrite("rem_capacity", &BDI::rem_capacity);

	py::enum_<BDI::IsFullyDischargedEnum>(vBDI, "IsFullyDischargedEnum", "Is Fully Discharged")
		.value("NOT_FULLY_DISCHARGED", BDI::IsFullyDischargedEnum::DSTATE_NOT_FULLY_DISCHARGED)
		.value("FULLY_DISCHARGED", BDI::IsFullyDischargedEnum::DSTATE_FULLY_DISCHARGED)
		.value("UNKNOWN", BDI::IsFullyDischargedEnum::DSTATE_UNKNOWN);

	py::enum_<BDI::IsFullyChargedEnum>(vBDI, "IsFullyChargedEnum", "Is Fully Charged")
		.value("NOT_FULLY_CHARGED", BDI::IsFullyChargedEnum::CSTATE_NOT_FULLY_CHARGED)
		.value("FULLY_CHARGED", BDI::IsFullyChargedEnum::CSTATE_FULLY_CHARGED)
		.value("UNKNOWN", BDI::IsFullyChargedEnum::CSTATE_UNKNOWN);

	py::enum_<BDI::RESTEnum>(vBDI, "RestEnum", "REST")
		.value("REST_NOT_SET", BDI::RESTEnum::REST_STATE_REST_NOT_SET)
		.value("REST_SET", BDI::RESTEnum::REST_STATE_REST_SET)
		.value("UNKNOWN", BDI::RESTEnum::REST_STATE_UNKNOWN);

	py::enum_<BDI::VDQEnum>(vBDI, "VdqEnum", "VDQ")
		.value("VDQ_NOT_SET", BDI::VDQEnum::VDQ_STATE_VDQ_NOT_SET)
		.value("VDQ_SET", BDI::VDQEnum::VDQ_STATE_VDQ_SET)
		.value("UNKNOWN", BDI::VDQEnum::VDQ_STATE_UNKNOWN);
}