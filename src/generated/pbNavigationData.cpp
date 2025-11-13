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

void pbNavigationData(py::module &m) {
	auto vNavigationData = py::class_<NavigationData, Message>(m, "NavigationData", "Navigation Data");
	vNavigationData.def(py::init<>());
	vNavigationData.def("__setstate__", &pbUnpickleMessage<NavigationData>);
	vNavigationData.def_readwrite("bias_psi", &NavigationData::bias_psi);
	vNavigationData.def_readwrite("bias_r", &NavigationData::bias_r);
	vNavigationData.def_readwrite("cog", &NavigationData::cog);
	vNavigationData.def_readwrite("cyaw", &NavigationData::cyaw);
	vNavigationData.def_readwrite("lbl_rej_level", &NavigationData::lbl_rej_level);
	vNavigationData.def_readwrite("gps_rej_level", &NavigationData::gps_rej_level);
	vNavigationData.def_readwrite("custom_x", &NavigationData::custom_x);
	vNavigationData.def_readwrite("custom_y", &NavigationData::custom_y);
	vNavigationData.def_readwrite("custom_z", &NavigationData::custom_z);
}