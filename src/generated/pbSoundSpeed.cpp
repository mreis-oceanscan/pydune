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

void pbSoundSpeed(py::module &m) {
	auto vSoundSpeed = py::class_<SoundSpeed, Message>(m, "SoundSpeed", "Sound Speed");
	vSoundSpeed.def(py::init<>());
	vSoundSpeed.def("__setstate__", &pbUnpickleMessage<SoundSpeed>);
	vSoundSpeed.def_readwrite("value", &SoundSpeed::value);
}