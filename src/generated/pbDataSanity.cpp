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

void pbDataSanity(py::module &m) {
	auto vDataSanity = py::class_<DataSanity, Message>(m, "DataSanity", "Data Sanity");
	vDataSanity.def(py::init<>());
	vDataSanity.def("__setstate__", &pbUnpickleMessage<DataSanity>);
	
	vDataSanity.def_property("sane",
	    [](const DataSanity &x){return static_cast<DataSanity::SanityEnum>(x.sane);},
	    [](DataSanity *x, const uint8_t &y){x->sane = y;},
	    "");

	py::enum_<DataSanity::SanityEnum>(vDataSanity, "SanityEnum", "Sanity")
		.value("SANE", DataSanity::SanityEnum::DS_SANE)
		.value("NOT_SANE", DataSanity::SanityEnum::DS_NOT_SANE);
}