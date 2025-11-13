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

void pbHistoricData(py::module &m) {
	auto vHistoricData = py::class_<HistoricData, Message>(m, "HistoricData", "Historic Data Series");
	vHistoricData.def(py::init<>());
	vHistoricData.def("__setstate__", &pbUnpickleMessage<HistoricData>);
	vHistoricData.def_readwrite("base_lat", &HistoricData::base_lat);
	vHistoricData.def_readwrite("base_lon", &HistoricData::base_lon);
	vHistoricData.def_readwrite("base_time", &HistoricData::base_time);
	vHistoricData.def_readwrite("data", &HistoricData::data);
}