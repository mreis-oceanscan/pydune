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

void pbSonarData(py::module &m) {
	auto vSonarData = py::class_<SonarData, Message>(m, "SonarData", "Sonar Data");
	vSonarData.def(py::init<>());
	vSonarData.def("__setstate__", &pbUnpickleMessage<SonarData>);
	
	vSonarData.def_property("type",
	    [](const SonarData &x){return static_cast<SonarData::TypeEnum>(x.type);},
	    [](SonarData *x, const uint8_t &y){x->type = y;},
	    "");
	vSonarData.def_readwrite("frequency", &SonarData::frequency);
	vSonarData.def_readwrite("min_range", &SonarData::min_range);
	vSonarData.def_readwrite("max_range", &SonarData::max_range);
	vSonarData.def_readwrite("bits_per_point", &SonarData::bits_per_point);
	vSonarData.def_readwrite("scale_factor", &SonarData::scale_factor);
	vSonarData.def_readwrite("beam_config", &SonarData::beam_config);
	
	vSonarData.def_property("data",
	    [](const SonarData &x){return py::bytes(x.data.data(), x.data.size());},
	    [](SonarData &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);

	py::enum_<SonarData::TypeEnum>(vSonarData, "TypeEnum", "Type")
		.value("SIDESCAN", SonarData::TypeEnum::ST_SIDESCAN)
		.value("ECHOSOUNDER", SonarData::TypeEnum::ST_ECHOSOUNDER)
		.value("MULTIBEAM", SonarData::TypeEnum::ST_MULTIBEAM)
		.value("PENCILBEAM", SonarData::TypeEnum::ST_PENCILBEAM);
}