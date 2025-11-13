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

void pbFormation(py::module &m) {
	auto vFormation = py::class_<Formation, Message>(m, "Formation", "Formation");
	vFormation.def(py::init<>());
	vFormation.def("__setstate__", &pbUnpickleMessage<Formation>);
	
	vFormation.def_property("formation_name",
	    [](const Formation &x){return ascii_to_unicode_safe(x.formation_name);},
	    [](Formation &x, std::string &s){x.formation_name = s;}, py::return_value_policy::take_ownership);
	
	vFormation.def_property("type",
	    [](const Formation &x){return static_cast<Formation::TypeEnum>(x.type);},
	    [](Formation *x, const uint8_t &y){x->type = y;},
	    "");
	
	vFormation.def_property("op",
	    [](const Formation &x){return static_cast<Formation::OperationEnum>(x.op);},
	    [](Formation *x, const uint8_t &y){x->op = y;},
	    "");
	
	vFormation.def_property("group_name",
	    [](const Formation &x){return ascii_to_unicode_safe(x.group_name);},
	    [](Formation &x, std::string &s){x.group_name = s;}, py::return_value_policy::take_ownership);
	
	vFormation.def_property("plan_id",
	    [](const Formation &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](Formation &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	
	vFormation.def_property("description",
	    [](const Formation &x){return ascii_to_unicode_safe(x.description);},
	    [](Formation &x, std::string &s){x.description = s;}, py::return_value_policy::take_ownership);
	
	vFormation.def_property("reference_frame",
	    [](const Formation &x){return static_cast<Formation::FormationReferenceFrameEnum>(x.reference_frame);},
	    [](Formation *x, const uint8_t &y){x->reference_frame = y;},
	    "");
	vFormation.def_readwrite("participants", &Formation::participants);
	vFormation.def_readwrite("leader_bank_lim", &Formation::leader_bank_lim);
	vFormation.def_readwrite("leader_speed_min", &Formation::leader_speed_min);
	vFormation.def_readwrite("leader_speed_max", &Formation::leader_speed_max);
	vFormation.def_readwrite("leader_alt_min", &Formation::leader_alt_min);
	vFormation.def_readwrite("leader_alt_max", &Formation::leader_alt_max);
	vFormation.def_readwrite("pos_sim_err_lim", &Formation::pos_sim_err_lim);
	vFormation.def_readwrite("pos_sim_err_wrn", &Formation::pos_sim_err_wrn);
	vFormation.def_readwrite("pos_sim_err_timeout", &Formation::pos_sim_err_timeout);
	vFormation.def_readwrite("converg_max", &Formation::converg_max);
	vFormation.def_readwrite("converg_timeout", &Formation::converg_timeout);
	vFormation.def_readwrite("comms_timeout", &Formation::comms_timeout);
	vFormation.def_readwrite("turb_lim", &Formation::turb_lim);
	
	vFormation.def_property("custom",
	    [](const Formation &x){return ascii_to_unicode_safe(x.custom);},
	    [](Formation &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<Formation::TypeEnum>(vFormation, "TypeEnum", "Type")
		.value("REQUEST", Formation::TypeEnum::FC_REQUEST)
		.value("REPORT", Formation::TypeEnum::FC_REPORT);

	py::enum_<Formation::OperationEnum>(vFormation, "OperationEnum", "Operation")
		.value("START", Formation::OperationEnum::OP_START)
		.value("STOP", Formation::OperationEnum::OP_STOP)
		.value("READY", Formation::OperationEnum::OP_READY)
		.value("EXECUTING", Formation::OperationEnum::OP_EXECUTING)
		.value("FAILURE", Formation::OperationEnum::OP_FAILURE);

	py::enum_<Formation::FormationReferenceFrameEnum>(vFormation, "FormationReferenceFrameEnum", "Formation Reference Frame")
		.value("EARTH_FIXED", Formation::FormationReferenceFrameEnum::OP_EARTH_FIXED)
		.value("PATH_FIXED", Formation::FormationReferenceFrameEnum::OP_PATH_FIXED)
		.value("PATH_CURVED", Formation::FormationReferenceFrameEnum::OP_PATH_CURVED);
}