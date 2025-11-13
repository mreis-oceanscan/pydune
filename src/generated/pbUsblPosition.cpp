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

void pbUsblPosition(py::module &m) {
	auto vUsblPosition = py::class_<UsblPosition, Message>(m, "UsblPosition", "USBL Position");
	vUsblPosition.def(py::init<>());
	vUsblPosition.def("__setstate__", &pbUnpickleMessage<UsblPosition>);
	vUsblPosition.def_readwrite("target", &UsblPosition::target);
	vUsblPosition.def_readwrite("x", &UsblPosition::x);
	vUsblPosition.def_readwrite("y", &UsblPosition::y);
	vUsblPosition.def_readwrite("z", &UsblPosition::z);
}