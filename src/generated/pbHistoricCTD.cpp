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

void pbHistoricCTD(py::module &m) {
	auto vHistoricCTD = py::class_<HistoricCTD, Message>(m, "HistoricCTD", "Historic CTD");
	vHistoricCTD.def(py::init<>());
	vHistoricCTD.def("__setstate__", &pbUnpickleMessage<HistoricCTD>);
	vHistoricCTD.def_readwrite("conductivity", &HistoricCTD::conductivity);
	vHistoricCTD.def_readwrite("temperature", &HistoricCTD::temperature);
	vHistoricCTD.def_readwrite("depth", &HistoricCTD::depth);
}