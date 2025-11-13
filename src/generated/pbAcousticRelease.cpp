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

void pbAcousticRelease(py::module &m) {
	auto vAcousticRelease = py::class_<AcousticRelease, Message>(m, "AcousticRelease", "Acoustic Release Request");
	vAcousticRelease.def(py::init<>());
	vAcousticRelease.def("__setstate__", &pbUnpickleMessage<AcousticRelease>);
	
	vAcousticRelease.def_property("system",
	    [](const AcousticRelease &x){return ascii_to_unicode_safe(x.system);},
	    [](AcousticRelease &x, std::string &s){x.system = s;}, py::return_value_policy::take_ownership);
	
	vAcousticRelease.def_property("op",
	    [](const AcousticRelease &x){return static_cast<AcousticRelease::OperationEnum>(x.op);},
	    [](AcousticRelease *x, const uint8_t &y){x->op = y;},
	    "");

	py::enum_<AcousticRelease::OperationEnum>(vAcousticRelease, "OperationEnum", "Operation")
		.value("OPEN", AcousticRelease::OperationEnum::AROP_OPEN)
		.value("CLOSE", AcousticRelease::OperationEnum::AROP_CLOSE);
}