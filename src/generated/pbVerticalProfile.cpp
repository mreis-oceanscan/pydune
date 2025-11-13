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

void pbVerticalProfile(py::module &m) {
	auto vVerticalProfile = py::class_<VerticalProfile, Message>(m, "VerticalProfile", "Vertical Profile");
	vVerticalProfile.def(py::init<>());
	vVerticalProfile.def("__setstate__", &pbUnpickleMessage<VerticalProfile>);
	
	vVerticalProfile.def_property("parameter",
	    [](const VerticalProfile &x){return static_cast<VerticalProfile::ParameterEnum>(x.parameter);},
	    [](VerticalProfile *x, const uint8_t &y){x->parameter = y;},
	    "");
	vVerticalProfile.def_readwrite("numsamples", &VerticalProfile::numsamples);
	vVerticalProfile.def_readwrite("samples", &VerticalProfile::samples);
	vVerticalProfile.def_readwrite("lat", &VerticalProfile::lat);
	vVerticalProfile.def_readwrite("lon", &VerticalProfile::lon);

	py::enum_<VerticalProfile::ParameterEnum>(vVerticalProfile, "ParameterEnum", "Parameter")
		.value("TEMPERATURE", VerticalProfile::ParameterEnum::PROF_TEMPERATURE)
		.value("SALINITY", VerticalProfile::ParameterEnum::PROF_SALINITY)
		.value("CONDUCTIVITY", VerticalProfile::ParameterEnum::PROF_CONDUCTIVITY)
		.value("PH", VerticalProfile::ParameterEnum::PROF_PH)
		.value("REDOX", VerticalProfile::ParameterEnum::PROF_REDOX)
		.value("CHLOROPHYLL", VerticalProfile::ParameterEnum::PROF_CHLOROPHYLL)
		.value("TURBIDITY", VerticalProfile::ParameterEnum::PROF_TURBIDITY)
		.value("CURRENT_VELOCITY_N", VerticalProfile::ParameterEnum::PROF_CURRENT_VELOCITY_N)
		.value("CURRENT_VELOCITY_E", VerticalProfile::ParameterEnum::PROF_CURRENT_VELOCITY_E)
		.value("ABSOLUTE_WIND_AVG", VerticalProfile::ParameterEnum::PROF_ABSOLUTE_WIND_AVG)
		.value("ABSOLUTE_WIND_MAX", VerticalProfile::ParameterEnum::PROF_ABSOLUTE_WIND_MAX)
		.value("DISS_ORGANIC_MATTER", VerticalProfile::ParameterEnum::PROF_DISS_ORGANIC_MATTER)
		.value("DISS_OXYGEN", VerticalProfile::ParameterEnum::PROF_DISS_OXYGEN);
}