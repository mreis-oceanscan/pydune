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

void pbLblRange(py::module &m) {
	auto vLblRange = py::class_<LblRange, Message>(m, "LblRange", "LBL Range");
	vLblRange.def(py::init<>());
	vLblRange.def("__setstate__", &pbUnpickleMessage<LblRange>);
	vLblRange.def_readwrite("id", &LblRange::id);
	vLblRange.def_readwrite("range", &LblRange::range);
}