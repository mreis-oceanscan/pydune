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

void pbEntityInfo(py::module &m) {
	auto vEntityInfo = py::class_<EntityInfo, Message>(m, "EntityInfo", "Entity Information");
	vEntityInfo.def(py::init<>());
	vEntityInfo.def("__setstate__", &pbUnpickleMessage<EntityInfo>);
	vEntityInfo.def_readwrite("id", &EntityInfo::id);
	
	vEntityInfo.def_property("label",
	    [](const EntityInfo &x){return ascii_to_unicode_safe(x.label);},
	    [](EntityInfo &x, std::string &s){x.label = s;}, py::return_value_policy::take_ownership);
	
	vEntityInfo.def_property("component",
	    [](const EntityInfo &x){return ascii_to_unicode_safe(x.component);},
	    [](EntityInfo &x, std::string &s){x.component = s;}, py::return_value_policy::take_ownership);
	vEntityInfo.def_readwrite("act_time", &EntityInfo::act_time);
	vEntityInfo.def_readwrite("deact_time", &EntityInfo::deact_time);
}