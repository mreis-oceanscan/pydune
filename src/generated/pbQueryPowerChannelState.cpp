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

void pbQueryPowerChannelState(py::module &m) {
	auto vQueryPowerChannelState = py::class_<QueryPowerChannelState, Message>(m, "QueryPowerChannelState", "Query Power Channel State");
	vQueryPowerChannelState.def(py::init<>());
	vQueryPowerChannelState.def("__setstate__", &pbUnpickleMessage<QueryPowerChannelState>);
}