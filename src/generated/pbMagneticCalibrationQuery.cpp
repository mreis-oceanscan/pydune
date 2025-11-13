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

void pbMagneticCalibrationQuery(py::module &m) {
	auto vMagneticCalibrationQuery = py::class_<MagneticCalibrationQuery, Message>(m, "MagneticCalibrationQuery", "Magnetic Calibration Query");
	vMagneticCalibrationQuery.def(py::init<>());
	vMagneticCalibrationQuery.def("__setstate__", &pbUnpickleMessage<MagneticCalibrationQuery>);
}