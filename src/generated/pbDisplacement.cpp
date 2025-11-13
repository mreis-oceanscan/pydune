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

void pbDisplacement(py::module &m) {
	auto vDisplacement = py::class_<Displacement, Message>(m, "Displacement", "Position Displacement");
	vDisplacement.def(py::init<>());
	vDisplacement.def("__setstate__", &pbUnpickleMessage<Displacement>);
	vDisplacement.def_readwrite("time", &Displacement::time);
	vDisplacement.def_readwrite("x", &Displacement::x);
	vDisplacement.def_readwrite("y", &Displacement::y);
	vDisplacement.def_readwrite("z", &Displacement::z);
}