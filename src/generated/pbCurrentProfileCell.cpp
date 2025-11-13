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

void pbCurrentProfileCell(py::module &m) {
	auto vCurrentProfileCell = py::class_<CurrentProfileCell, Message>(m, "CurrentProfileCell", "Current Profile Cell");
	vCurrentProfileCell.def(py::init<>());
	vCurrentProfileCell.def("__setstate__", &pbUnpickleMessage<CurrentProfileCell>);
	vCurrentProfileCell.def_readwrite("cell_position", &CurrentProfileCell::cell_position);
	vCurrentProfileCell.def_readwrite("beams", &CurrentProfileCell::beams);
}