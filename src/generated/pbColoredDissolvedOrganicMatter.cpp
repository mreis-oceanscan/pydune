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

void pbColoredDissolvedOrganicMatter(py::module &m) {
	auto vColoredDissolvedOrganicMatter = py::class_<ColoredDissolvedOrganicMatter, Message>(m, "ColoredDissolvedOrganicMatter", "Colored Dissolved Organic Matter");
	vColoredDissolvedOrganicMatter.def(py::init<>());
	vColoredDissolvedOrganicMatter.def("__setstate__", &pbUnpickleMessage<ColoredDissolvedOrganicMatter>);
	vColoredDissolvedOrganicMatter.def_readwrite("value", &ColoredDissolvedOrganicMatter::value);
}