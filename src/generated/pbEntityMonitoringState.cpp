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

void pbEntityMonitoringState(py::module &m) {
	auto vEntityMonitoringState = py::class_<EntityMonitoringState, Message>(m, "EntityMonitoringState", "Entity Monitoring State");
	vEntityMonitoringState.def(py::init<>());
	vEntityMonitoringState.def("__setstate__", &pbUnpickleMessage<EntityMonitoringState>);
	vEntityMonitoringState.def_readwrite("mcount", &EntityMonitoringState::mcount);
	
	vEntityMonitoringState.def_property("mnames",
	    [](const EntityMonitoringState &x){return ascii_to_unicode_safe(x.mnames);},
	    [](EntityMonitoringState &x, std::string &s){x.mnames = s;}, py::return_value_policy::take_ownership);
	vEntityMonitoringState.def_readwrite("ecount", &EntityMonitoringState::ecount);
	
	vEntityMonitoringState.def_property("enames",
	    [](const EntityMonitoringState &x){return ascii_to_unicode_safe(x.enames);},
	    [](EntityMonitoringState &x, std::string &s){x.enames = s;}, py::return_value_policy::take_ownership);
	vEntityMonitoringState.def_readwrite("ccount", &EntityMonitoringState::ccount);
	
	vEntityMonitoringState.def_property("cnames",
	    [](const EntityMonitoringState &x){return ascii_to_unicode_safe(x.cnames);},
	    [](EntityMonitoringState &x, std::string &s){x.cnames = s;}, py::return_value_policy::take_ownership);
	
	vEntityMonitoringState.def_property("last_error",
	    [](const EntityMonitoringState &x){return ascii_to_unicode_safe(x.last_error);},
	    [](EntityMonitoringState &x, std::string &s){x.last_error = s;}, py::return_value_policy::take_ownership);
	vEntityMonitoringState.def_readwrite("last_error_time", &EntityMonitoringState::last_error_time);
}