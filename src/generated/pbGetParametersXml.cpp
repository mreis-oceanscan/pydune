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

void pbGetParametersXml(py::module &m) {
	auto vGetParametersXml = py::class_<GetParametersXml, Message>(m, "GetParametersXml", "Get Parameters XML");
	vGetParametersXml.def(py::init<>());
	vGetParametersXml.def("__setstate__", &pbUnpickleMessage<GetParametersXml>);
}