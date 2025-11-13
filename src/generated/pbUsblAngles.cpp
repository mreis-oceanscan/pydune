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

void pbUsblAngles(py::module &m) {
	auto vUsblAngles = py::class_<UsblAngles, Message>(m, "UsblAngles", "USBL Angles");
	vUsblAngles.def(py::init<>());
	vUsblAngles.def("__setstate__", &pbUnpickleMessage<UsblAngles>);
	vUsblAngles.def_readwrite("target", &UsblAngles::target);
	vUsblAngles.def_readwrite("bearing", &UsblAngles::bearing);
	vUsblAngles.def_readwrite("elevation", &UsblAngles::elevation);
}