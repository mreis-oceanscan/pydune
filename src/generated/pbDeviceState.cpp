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

void pbDeviceState(py::module &m) {
	auto vDeviceState = py::class_<DeviceState, Message>(m, "DeviceState", "Device State");
	vDeviceState.def(py::init<>());
	vDeviceState.def("__setstate__", &pbUnpickleMessage<DeviceState>);
	vDeviceState.def_readwrite("x", &DeviceState::x);
	vDeviceState.def_readwrite("y", &DeviceState::y);
	vDeviceState.def_readwrite("z", &DeviceState::z);
	vDeviceState.def_readwrite("phi", &DeviceState::phi);
	vDeviceState.def_readwrite("theta", &DeviceState::theta);
	vDeviceState.def_readwrite("psi", &DeviceState::psi);
}