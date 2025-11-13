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

void pbAmmonium(py::module &m) {
	auto vAmmonium = py::class_<Ammonium, Message>(m, "Ammonium", "Ammonium");
	vAmmonium.def(py::init<>());
	vAmmonium.def("__setstate__", &pbUnpickleMessage<Ammonium>);
	vAmmonium.def_readwrite("value", &Ammonium::value);
}