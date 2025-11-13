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

void pbSatellitesInView(py::module &m) {
	auto vSatellitesInView = py::class_<SatellitesInView, Message>(m, "SatellitesInView", "Satellites in View");
	vSatellitesInView.def(py::init<>());
	vSatellitesInView.def("__setstate__", &pbUnpickleMessage<SatellitesInView>);
	vSatellitesInView.def_readwrite("nsat", &SatellitesInView::nsat);
}