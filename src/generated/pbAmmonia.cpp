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

void pbAmmonia(py::module &m) {
	auto vAmmonia = py::class_<Ammonia, Message>(m, "Ammonia", "Ammonia");
	vAmmonia.def(py::init<>());
	vAmmonia.def("__setstate__", &pbUnpickleMessage<Ammonia>);
	vAmmonia.def_readwrite("value", &Ammonia::value);
}