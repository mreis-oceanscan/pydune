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

void pbNitrateN(py::module &m) {
	auto vNitrateN = py::class_<NitrateN, Message>(m, "NitrateN", "Nitrate-N");
	vNitrateN.def(py::init<>());
	vNitrateN.def("__setstate__", &pbUnpickleMessage<NitrateN>);
	vNitrateN.def_readwrite("value", &NitrateN::value);
}