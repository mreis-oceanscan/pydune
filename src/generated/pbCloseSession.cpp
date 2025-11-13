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

void pbCloseSession(py::module &m) {
	auto vCloseSession = py::class_<CloseSession, Message>(m, "CloseSession", "Close Session");
	vCloseSession.def(py::init<>());
	vCloseSession.def("__setstate__", &pbUnpickleMessage<CloseSession>);
	vCloseSession.def_readwrite("sessid", &CloseSession::sessid);
}