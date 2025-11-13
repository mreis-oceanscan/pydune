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

void pbEntityState(py::module &m) {
	auto vEntityState = py::class_<EntityState, Message>(m, "EntityState", "Entity State");
	vEntityState.def(py::init<>());
	vEntityState.def("__setstate__", &pbUnpickleMessage<EntityState>);
	
	vEntityState.def_property("state",
	    [](const EntityState &x){return static_cast<EntityState::StateEnum>(x.state);},
	    [](EntityState *x, const uint8_t &y){x->state = y;},
	    "");
	vEntityState.def_readwrite("flags", &EntityState::flags);
	
	vEntityState.def_property("description",
	    [](const EntityState &x){return ascii_to_unicode_safe(x.description);},
	    [](EntityState &x, std::string &s){x.description = s;}, py::return_value_policy::take_ownership);

	py::enum_<EntityState::StateEnum>(vEntityState, "StateEnum", "State")
		.value("BOOT", EntityState::StateEnum::ESTA_BOOT)
		.value("NORMAL", EntityState::StateEnum::ESTA_NORMAL)
		.value("FAULT", EntityState::StateEnum::ESTA_FAULT)
		.value("ERROR", EntityState::StateEnum::ESTA_ERROR)
		.value("FAILURE", EntityState::StateEnum::ESTA_FAILURE);

	py::enum_<EntityState::FlagsBits>(vEntityState, "FlagsBits", "Flags", py::arithmetic())
		.value("HUMAN_INTERVENTION", EntityState::FlagsBits::EFLA_HUMAN_INTERVENTION);
}