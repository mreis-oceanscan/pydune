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

void pbSoiPlan(py::module &m) {
	auto vSoiPlan = py::class_<SoiPlan, Message>(m, "SoiPlan", "SOI Plan");
	vSoiPlan.def(py::init<>());
	vSoiPlan.def("__setstate__", &pbUnpickleMessage<SoiPlan>);
	vSoiPlan.def_readwrite("plan_id", &SoiPlan::plan_id);
	vSoiPlan.def_readwrite("waypoints", &SoiPlan::waypoints);
}