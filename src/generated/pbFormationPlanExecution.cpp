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

void pbFormationPlanExecution(py::module &m) {
	auto vFormationPlanExecution = py::class_<FormationPlanExecution, Maneuver>(m, "FormationPlanExecution", "Formation Plan Execution");
	vFormationPlanExecution.def(py::init<>());
	vFormationPlanExecution.def("__setstate__", &pbUnpickleMessage<FormationPlanExecution>);
	
	vFormationPlanExecution.def_property("group_name",
	    [](const FormationPlanExecution &x){return ascii_to_unicode_safe(x.group_name);},
	    [](FormationPlanExecution &x, std::string &s){x.group_name = s;}, py::return_value_policy::take_ownership);
	
	vFormationPlanExecution.def_property("formation_name",
	    [](const FormationPlanExecution &x){return ascii_to_unicode_safe(x.formation_name);},
	    [](FormationPlanExecution &x, std::string &s){x.formation_name = s;}, py::return_value_policy::take_ownership);
	
	vFormationPlanExecution.def_property("plan_id",
	    [](const FormationPlanExecution &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](FormationPlanExecution &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	
	vFormationPlanExecution.def_property("description",
	    [](const FormationPlanExecution &x){return ascii_to_unicode_safe(x.description);},
	    [](FormationPlanExecution &x, std::string &s){x.description = s;}, py::return_value_policy::take_ownership);
	vFormationPlanExecution.def_readwrite("leader_speed", &FormationPlanExecution::leader_speed);
	vFormationPlanExecution.def_readwrite("leader_bank_lim", &FormationPlanExecution::leader_bank_lim);
	vFormationPlanExecution.def_readwrite("pos_sim_err_lim", &FormationPlanExecution::pos_sim_err_lim);
	vFormationPlanExecution.def_readwrite("pos_sim_err_wrn", &FormationPlanExecution::pos_sim_err_wrn);
	vFormationPlanExecution.def_readwrite("pos_sim_err_timeout", &FormationPlanExecution::pos_sim_err_timeout);
	vFormationPlanExecution.def_readwrite("converg_max", &FormationPlanExecution::converg_max);
	vFormationPlanExecution.def_readwrite("converg_timeout", &FormationPlanExecution::converg_timeout);
	vFormationPlanExecution.def_readwrite("comms_timeout", &FormationPlanExecution::comms_timeout);
	vFormationPlanExecution.def_readwrite("turb_lim", &FormationPlanExecution::turb_lim);
	
	vFormationPlanExecution.def_property("custom",
	    [](const FormationPlanExecution &x){return ascii_to_unicode_safe(x.custom);},
	    [](FormationPlanExecution &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}