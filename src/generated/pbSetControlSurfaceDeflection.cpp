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

void pbSetControlSurfaceDeflection(py::module &m) {
	auto vSetControlSurfaceDeflection = py::class_<SetControlSurfaceDeflection, Message>(m, "SetControlSurfaceDeflection", "Set Control Surface Deflection");
	vSetControlSurfaceDeflection.def(py::init<>());
	vSetControlSurfaceDeflection.def("__setstate__", &pbUnpickleMessage<SetControlSurfaceDeflection>);
	vSetControlSurfaceDeflection.def_readwrite("id", &SetControlSurfaceDeflection::id);
	vSetControlSurfaceDeflection.def_readwrite("angle", &SetControlSurfaceDeflection::angle);
}