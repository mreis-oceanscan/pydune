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

void pbNitrate(py::module &m) {
	auto vNitrate = py::class_<Nitrate, Message>(m, "Nitrate", "Nitrate");
	vNitrate.def(py::init<>());
	vNitrate.def("__setstate__", &pbUnpickleMessage<Nitrate>);
	vNitrate.def_readwrite("value", &Nitrate::value);
}