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

void pbADCPBeam(py::module &m) {
	auto vADCPBeam = py::class_<ADCPBeam, Message>(m, "ADCPBeam", "ADCP Beam Measurements");
	vADCPBeam.def(py::init<>());
	vADCPBeam.def("__setstate__", &pbUnpickleMessage<ADCPBeam>);
	vADCPBeam.def_readwrite("vel", &ADCPBeam::vel);
	vADCPBeam.def_readwrite("amp", &ADCPBeam::amp);
	vADCPBeam.def_readwrite("cor", &ADCPBeam::cor);
}