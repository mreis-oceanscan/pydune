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

void pbIoEvent(py::module &m) {
	auto vIoEvent = py::class_<IoEvent, Message>(m, "IoEvent", "I/O Event");
	vIoEvent.def(py::init<>());
	vIoEvent.def("__setstate__", &pbUnpickleMessage<IoEvent>);
	
	vIoEvent.def_property("type",
	    [](const IoEvent &x){return static_cast<IoEvent::TypeEnum>(x.type);},
	    [](IoEvent *x, const uint8_t &y){x->type = y;},
	    "");
	
	vIoEvent.def_property("error",
	    [](const IoEvent &x){return ascii_to_unicode_safe(x.error);},
	    [](IoEvent &x, std::string &s){x.error = s;}, py::return_value_policy::take_ownership);

	py::enum_<IoEvent::TypeEnum>(vIoEvent, "TypeEnum", "Type")
		.value("INPUT", IoEvent::TypeEnum::IOV_TYPE_INPUT)
		.value("INPUT_ERROR", IoEvent::TypeEnum::IOV_TYPE_INPUT_ERROR);
}