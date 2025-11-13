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

void pbSessionKeepAlive(py::module &m) {
	auto vSessionKeepAlive = py::class_<SessionKeepAlive, Message>(m, "SessionKeepAlive", "Session Keep-Alive");
	vSessionKeepAlive.def(py::init<>());
	vSessionKeepAlive.def("__setstate__", &pbUnpickleMessage<SessionKeepAlive>);
	vSessionKeepAlive.def_readwrite("sessid", &SessionKeepAlive::sessid);
}