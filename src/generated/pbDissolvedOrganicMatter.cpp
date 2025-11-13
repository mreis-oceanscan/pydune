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

void pbDissolvedOrganicMatter(py::module &m) {
	auto vDissolvedOrganicMatter = py::class_<DissolvedOrganicMatter, Message>(m, "DissolvedOrganicMatter", "Dissolved Organic Matter");
	vDissolvedOrganicMatter.def(py::init<>());
	vDissolvedOrganicMatter.def("__setstate__", &pbUnpickleMessage<DissolvedOrganicMatter>);
	vDissolvedOrganicMatter.def_readwrite("value", &DissolvedOrganicMatter::value);
	
	vDissolvedOrganicMatter.def_property("type",
	    [](const DissolvedOrganicMatter &x){return static_cast<DissolvedOrganicMatter::TypeofmeasurementEnum>(x.type);},
	    [](DissolvedOrganicMatter *x, const uint8_t &y){x->type = y;},
	    "");

	py::enum_<DissolvedOrganicMatter::TypeofmeasurementEnum>(vDissolvedOrganicMatter, "TypeOfMeasurementEnum", "Type of measurement")
		.value("COLORED", DissolvedOrganicMatter::TypeofmeasurementEnum::DT_COLORED)
		.value("FLUORESCENT", DissolvedOrganicMatter::TypeofmeasurementEnum::DT_FLUORESCENT);
}