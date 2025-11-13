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

void pbSystemGroup(py::module &m) {
	auto vSystemGroup = py::class_<SystemGroup, Message>(m, "SystemGroup", "System Group");
	vSystemGroup.def(py::init<>());
	vSystemGroup.def("__setstate__", &pbUnpickleMessage<SystemGroup>);
	
	vSystemGroup.def_property("groupname",
	    [](const SystemGroup &x){return ascii_to_unicode_safe(x.groupname);},
	    [](SystemGroup &x, std::string &s){x.groupname = s;}, py::return_value_policy::take_ownership);
	
	vSystemGroup.def_property("action",
	    [](const SystemGroup &x){return static_cast<SystemGroup::GroupListActionEnum>(x.action);},
	    [](SystemGroup *x, const uint8_t &y){x->action = y;},
	    "");
	
	vSystemGroup.def_property("grouplist",
	    [](const SystemGroup &x){return ascii_to_unicode_safe(x.grouplist);},
	    [](SystemGroup &x, std::string &s){x.grouplist = s;}, py::return_value_policy::take_ownership);

	py::enum_<SystemGroup::GroupListActionEnum>(vSystemGroup, "GroupListActionEnum", "Group List Action")
		.value("Dis", SystemGroup::GroupListActionEnum::OP_Dis)
		.value("Set", SystemGroup::GroupListActionEnum::OP_Set)
		.value("Req", SystemGroup::GroupListActionEnum::OP_Req)
		.value("Chg", SystemGroup::GroupListActionEnum::OP_Chg)
		.value("Rep", SystemGroup::GroupListActionEnum::OP_Rep)
		.value("Frc", SystemGroup::GroupListActionEnum::OP_Frc);
}