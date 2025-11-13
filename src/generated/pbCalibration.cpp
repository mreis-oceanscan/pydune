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

void pbCalibration(py::module &m) {
	auto vCalibration = py::class_<Calibration, Message>(m, "Calibration", "Calibration");
	vCalibration.def(py::init<>());
	vCalibration.def("__setstate__", &pbUnpickleMessage<Calibration>);
	vCalibration.def_readwrite("duration", &Calibration::duration);
}