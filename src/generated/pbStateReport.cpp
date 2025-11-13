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

void pbStateReport(py::module &m) {
	auto vStateReport = py::class_<StateReport, Message>(m, "StateReport", "State Report");
	vStateReport.def(py::init<>());
	vStateReport.def("__setstate__", &pbUnpickleMessage<StateReport>);
	vStateReport.def_readwrite("stime", &StateReport::stime);
	vStateReport.def_readwrite("latitude", &StateReport::latitude);
	vStateReport.def_readwrite("longitude", &StateReport::longitude);
	vStateReport.def_readwrite("altitude", &StateReport::altitude);
	vStateReport.def_readwrite("depth", &StateReport::depth);
	vStateReport.def_readwrite("heading", &StateReport::heading);
	vStateReport.def_readwrite("speed", &StateReport::speed);
	vStateReport.def_readwrite("fuel", &StateReport::fuel);
	vStateReport.def_readwrite("exec_state", &StateReport::exec_state);
	vStateReport.def_readwrite("plan_checksum", &StateReport::plan_checksum);
}