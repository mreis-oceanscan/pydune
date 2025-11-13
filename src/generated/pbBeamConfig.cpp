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

void pbBeamConfig(py::module &m) {
	auto vBeamConfig = py::class_<BeamConfig, Message>(m, "BeamConfig", "Beam Configuration");
	vBeamConfig.def(py::init<>());
	vBeamConfig.def("__setstate__", &pbUnpickleMessage<BeamConfig>);
	vBeamConfig.def_readwrite("beam_width", &BeamConfig::beam_width);
	vBeamConfig.def_readwrite("beam_height", &BeamConfig::beam_height);
}