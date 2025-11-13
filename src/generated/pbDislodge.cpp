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

void pbDislodge(py::module &m) {
	auto vDislodge = py::class_<Dislodge, Maneuver>(m, "Dislodge", "Dislodge Maneuver");
	vDislodge.def(py::init<>());
	vDislodge.def("__setstate__", &pbUnpickleMessage<Dislodge>);
	vDislodge.def_readwrite("timeout", &Dislodge::timeout);
	vDislodge.def_readwrite("rpm", &Dislodge::rpm);
	
	vDislodge.def_property("direction",
	    [](const Dislodge &x){return static_cast<Dislodge::DirectionEnum>(x.direction);},
	    [](Dislodge *x, const uint8_t &y){x->direction = y;},
	    "");
	
	vDislodge.def_property("custom",
	    [](const Dislodge &x){return ascii_to_unicode_safe(x.custom);},
	    [](Dislodge &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<Dislodge::DirectionEnum>(vDislodge, "DirectionEnum", "Direction")
		.value("AUTO", Dislodge::DirectionEnum::DIR_AUTO)
		.value("FORWARD", Dislodge::DirectionEnum::DIR_FORWARD)
		.value("BACKWARD", Dislodge::DirectionEnum::DIR_BACKWARD);
}