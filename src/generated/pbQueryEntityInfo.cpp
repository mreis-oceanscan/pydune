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

void pbQueryEntityInfo(py::module &m) {
	auto vQueryEntityInfo = py::class_<QueryEntityInfo, Message>(m, "QueryEntityInfo", "Query Entity Information");
	vQueryEntityInfo.def(py::init<>());
	vQueryEntityInfo.def("__setstate__", &pbUnpickleMessage<QueryEntityInfo>);
	vQueryEntityInfo.def_readwrite("id", &QueryEntityInfo::id);
}