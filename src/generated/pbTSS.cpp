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

void pbTSS(py::module &m) {
	auto vTSS = py::class_<TSS, Message>(m, "TSS", "Total Suspended Solids");
	vTSS.def(py::init<>());
	vTSS.def("__setstate__", &pbUnpickleMessage<TSS>);
	vTSS.def_readwrite("value", &TSS::value);
}