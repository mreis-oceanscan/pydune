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

void pbGetOperationalLimits(py::module &m) {
	auto vGetOperationalLimits = py::class_<GetOperationalLimits, Message>(m, "GetOperationalLimits", "Get Operational Limits");
	vGetOperationalLimits.def(py::init<>());
	vGetOperationalLimits.def("__setstate__", &pbUnpickleMessage<GetOperationalLimits>);
}