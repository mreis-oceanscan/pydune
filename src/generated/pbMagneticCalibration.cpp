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

void pbMagneticCalibration(py::module &m) {
	auto vMagneticCalibration = py::class_<MagneticCalibration, Message>(m, "MagneticCalibration", "Magnetic Calibration");
	vMagneticCalibration.def(py::init<>());
	vMagneticCalibration.def("__setstate__", &pbUnpickleMessage<MagneticCalibration>);
	vMagneticCalibration.def_readwrite("utc_time", &MagneticCalibration::utc_time);
	vMagneticCalibration.def_readwrite("lat", &MagneticCalibration::lat);
	vMagneticCalibration.def_readwrite("lon", &MagneticCalibration::lon);
	vMagneticCalibration.def_readwrite("height", &MagneticCalibration::height);
	vMagneticCalibration.def_readwrite("hard_x", &MagneticCalibration::hard_x);
	vMagneticCalibration.def_readwrite("hard_y", &MagneticCalibration::hard_y);
	vMagneticCalibration.def_readwrite("hard_z", &MagneticCalibration::hard_z);
	vMagneticCalibration.def_readwrite("soft_xx", &MagneticCalibration::soft_xx);
	vMagneticCalibration.def_readwrite("soft_yy", &MagneticCalibration::soft_yy);
	vMagneticCalibration.def_readwrite("soft_zz", &MagneticCalibration::soft_zz);
	vMagneticCalibration.def_readwrite("soft_xy", &MagneticCalibration::soft_xy);
	vMagneticCalibration.def_readwrite("soft_xz", &MagneticCalibration::soft_xz);
	vMagneticCalibration.def_readwrite("soft_yz", &MagneticCalibration::soft_yz);
	vMagneticCalibration.def_readwrite("mag_strength", &MagneticCalibration::mag_strength);
}