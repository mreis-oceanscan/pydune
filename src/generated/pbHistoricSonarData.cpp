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

void pbHistoricSonarData(py::module &m) {
	auto vHistoricSonarData = py::class_<HistoricSonarData, Message>(m, "HistoricSonarData", "Historic Sonar Data");
	vHistoricSonarData.def(py::init<>());
	vHistoricSonarData.def("__setstate__", &pbUnpickleMessage<HistoricSonarData>);
	vHistoricSonarData.def_readwrite("altitude", &HistoricSonarData::altitude);
	vHistoricSonarData.def_readwrite("width", &HistoricSonarData::width);
	vHistoricSonarData.def_readwrite("length", &HistoricSonarData::length);
	vHistoricSonarData.def_readwrite("bearing", &HistoricSonarData::bearing);
	vHistoricSonarData.def_readwrite("pxl", &HistoricSonarData::pxl);
	
	vHistoricSonarData.def_property("encoding",
	    [](const HistoricSonarData &x){return static_cast<HistoricSonarData::EncodingEnum>(x.encoding);},
	    [](HistoricSonarData *x, const uint8_t &y){x->encoding = y;},
	    "");
	
	vHistoricSonarData.def_property("sonar_data",
	    [](const HistoricSonarData &x){return py::bytes(x.sonar_data.data(), x.sonar_data.size());},
	    [](HistoricSonarData &x, py::bytes &b){bytes_to_vector(b, x.sonar_data);}, py::return_value_policy::take_ownership);

	py::enum_<HistoricSonarData::EncodingEnum>(vHistoricSonarData, "EncodingEnum", "Encoding")
		.value("ONE_BYTE_PER_PIXEL", HistoricSonarData::EncodingEnum::ENC_ONE_BYTE_PER_PIXEL)
		.value("PNG", HistoricSonarData::EncodingEnum::ENC_PNG)
		.value("JPEG", HistoricSonarData::EncodingEnum::ENC_JPEG);
}