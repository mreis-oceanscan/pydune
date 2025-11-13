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

void pbMonitorEntityState(py::module &m) {
	auto vMonitorEntityState = py::class_<MonitorEntityState, Message>(m, "MonitorEntityState", "Monitor Entity State");
	vMonitorEntityState.def(py::init<>());
	vMonitorEntityState.def("__setstate__", &pbUnpickleMessage<MonitorEntityState>);
	
	vMonitorEntityState.def_property("command",
	    [](const MonitorEntityState &x){return static_cast<MonitorEntityState::CommandEnum>(x.command);},
	    [](MonitorEntityState *x, const uint8_t &y){x->command = y;},
	    "");
	
	vMonitorEntityState.def_property("entities",
	    [](const MonitorEntityState &x){return ascii_to_unicode_safe(x.entities);},
	    [](MonitorEntityState &x, std::string &s){x.entities = s;}, py::return_value_policy::take_ownership);

	py::enum_<MonitorEntityState::CommandEnum>(vMonitorEntityState, "CommandEnum", "Command")
		.value("RESET", MonitorEntityState::CommandEnum::MES_RESET)
		.value("ENABLE", MonitorEntityState::CommandEnum::MES_ENABLE)
		.value("DISABLE", MonitorEntityState::CommandEnum::MES_DISABLE)
		.value("ENABLE_EXCLUSIVE", MonitorEntityState::CommandEnum::MES_ENABLE_EXCLUSIVE)
		.value("STATUS", MonitorEntityState::CommandEnum::MES_STATUS);
}