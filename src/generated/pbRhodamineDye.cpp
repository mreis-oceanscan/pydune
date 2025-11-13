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

void pbRhodamineDye(py::module &m) {
	auto vRhodamineDye = py::class_<RhodamineDye, Message>(m, "RhodamineDye", "Rhodamine Dye");
	vRhodamineDye.def(py::init<>());
	vRhodamineDye.def("__setstate__", &pbUnpickleMessage<RhodamineDye>);
	vRhodamineDye.def_readwrite("value", &RhodamineDye::value);
}