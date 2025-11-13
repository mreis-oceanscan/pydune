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

void pbDistance(py::module &m) {
	auto vDistance = py::class_<Distance, Message>(m, "Distance", "Distance");
	vDistance.def(py::init<>());
	vDistance.def("__setstate__", &pbUnpickleMessage<Distance>);
	
	vDistance.def_property("validity",
	    [](const Distance &x){return static_cast<Distance::ValidityEnum>(x.validity);},
	    [](Distance *x, const uint8_t &y){x->validity = y;},
	    "");
	vDistance.def_readwrite("location", &Distance::location);
	vDistance.def_readwrite("beam_config", &Distance::beam_config);
	vDistance.def_readwrite("value", &Distance::value);

	py::enum_<Distance::ValidityEnum>(vDistance, "ValidityEnum", "Validity")
		.value("INVALID", Distance::ValidityEnum::DV_INVALID)
		.value("VALID", Distance::ValidityEnum::DV_VALID);
}