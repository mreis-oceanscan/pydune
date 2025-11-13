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

void pbGpsNavData(py::module &m) {
	auto vGpsNavData = py::class_<GpsNavData, Message>(m, "GpsNavData", "GPS Navigation Data");
	vGpsNavData.def(py::init<>());
	vGpsNavData.def("__setstate__", &pbUnpickleMessage<GpsNavData>);
	vGpsNavData.def_readwrite("itow", &GpsNavData::itow);
	vGpsNavData.def_readwrite("lat", &GpsNavData::lat);
	vGpsNavData.def_readwrite("lon", &GpsNavData::lon);
	vGpsNavData.def_readwrite("height_ell", &GpsNavData::height_ell);
	vGpsNavData.def_readwrite("height_sea", &GpsNavData::height_sea);
	vGpsNavData.def_readwrite("hacc", &GpsNavData::hacc);
	vGpsNavData.def_readwrite("vacc", &GpsNavData::vacc);
	vGpsNavData.def_readwrite("vel_n", &GpsNavData::vel_n);
	vGpsNavData.def_readwrite("vel_e", &GpsNavData::vel_e);
	vGpsNavData.def_readwrite("vel_d", &GpsNavData::vel_d);
	vGpsNavData.def_readwrite("speed", &GpsNavData::speed);
	vGpsNavData.def_readwrite("gspeed", &GpsNavData::gspeed);
	vGpsNavData.def_readwrite("heading", &GpsNavData::heading);
	vGpsNavData.def_readwrite("sacc", &GpsNavData::sacc);
	vGpsNavData.def_readwrite("cacc", &GpsNavData::cacc);
}