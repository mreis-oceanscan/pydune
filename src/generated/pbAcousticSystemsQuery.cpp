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

void pbAcousticSystemsQuery(py::module &m) {
	auto vAcousticSystemsQuery = py::class_<AcousticSystemsQuery, Message>(m, "AcousticSystemsQuery", "Acoustic Systems Query");
	vAcousticSystemsQuery.def(py::init<>());
	vAcousticSystemsQuery.def("__setstate__", &pbUnpickleMessage<AcousticSystemsQuery>);
}