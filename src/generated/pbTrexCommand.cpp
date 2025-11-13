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

void pbTrexCommand(py::module &m) {
	auto vTrexCommand = py::class_<TrexCommand, Message>(m, "TrexCommand", "TREX Command");
	vTrexCommand.def(py::init<>());
	vTrexCommand.def("__setstate__", &pbUnpickleMessage<TrexCommand>);
	
	vTrexCommand.def_property("command",
	    [](const TrexCommand &x){return static_cast<TrexCommand::CommandEnum>(x.command);},
	    [](TrexCommand *x, const uint8_t &y){x->command = y;},
	    "");
	
	vTrexCommand.def_property("goal_id",
	    [](const TrexCommand &x){return ascii_to_unicode_safe(x.goal_id);},
	    [](TrexCommand &x, std::string &s){x.goal_id = s;}, py::return_value_policy::take_ownership);
	
	vTrexCommand.def_property("goal_xml",
	    [](const TrexCommand &x){return ascii_to_unicode_safe(x.goal_xml);},
	    [](TrexCommand &x, std::string &s){x.goal_xml = s;}, py::return_value_policy::take_ownership);

	py::enum_<TrexCommand::CommandEnum>(vTrexCommand, "CommandEnum", "Command")
		.value("DISABLE", TrexCommand::CommandEnum::OP_DISABLE)
		.value("ENABLE", TrexCommand::CommandEnum::OP_ENABLE)
		.value("POST_GOAL", TrexCommand::CommandEnum::OP_POST_GOAL)
		.value("RECALL_GOAL", TrexCommand::CommandEnum::OP_RECALL_GOAL)
		.value("REQUEST_PLAN", TrexCommand::CommandEnum::OP_REQUEST_PLAN)
		.value("REPORT_PLAN", TrexCommand::CommandEnum::OP_REPORT_PLAN);
}