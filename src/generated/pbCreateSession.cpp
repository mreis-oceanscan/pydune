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

void pbCreateSession(py::module &m) {
	auto vCreateSession = py::class_<CreateSession, Message>(m, "CreateSession", "Create Session");
	vCreateSession.def(py::init<>());
	vCreateSession.def("__setstate__", &pbUnpickleMessage<CreateSession>);
	vCreateSession.def_readwrite("timeout", &CreateSession::timeout);
}