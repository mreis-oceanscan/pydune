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

void pbQueryEntityState(py::module &m) {
	auto vQueryEntityState = py::class_<QueryEntityState, Message>(m, "QueryEntityState", "Query Entity State");
	vQueryEntityState.def(py::init<>());
	vQueryEntityState.def("__setstate__", &pbUnpickleMessage<QueryEntityState>);
}