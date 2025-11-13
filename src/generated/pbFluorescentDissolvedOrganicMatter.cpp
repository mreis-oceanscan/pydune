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

void pbFluorescentDissolvedOrganicMatter(py::module &m) {
	auto vFluorescentDissolvedOrganicMatter = py::class_<FluorescentDissolvedOrganicMatter, Message>(m, "FluorescentDissolvedOrganicMatter", "Fluorescent Dissolved Organic Matter");
	vFluorescentDissolvedOrganicMatter.def(py::init<>());
	vFluorescentDissolvedOrganicMatter.def("__setstate__", &pbUnpickleMessage<FluorescentDissolvedOrganicMatter>);
	vFluorescentDissolvedOrganicMatter.def_readwrite("value", &FluorescentDissolvedOrganicMatter::value);
}