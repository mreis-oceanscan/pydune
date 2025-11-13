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

void pbChloride(py::module &m) {
	auto vChloride = py::class_<Chloride, Message>(m, "Chloride", "Chloride");
	vChloride.def(py::init<>());
	vChloride.def("__setstate__", &pbUnpickleMessage<Chloride>);
	vChloride.def_readwrite("value", &Chloride::value);
}