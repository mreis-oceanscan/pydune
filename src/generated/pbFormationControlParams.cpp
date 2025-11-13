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

void pbFormationControlParams(py::module &m) {
	auto vFormationControlParams = py::class_<FormationControlParams, Message>(m, "FormationControlParams", "Formation Control Parameters");
	vFormationControlParams.def(py::init<>());
	vFormationControlParams.def("__setstate__", &pbUnpickleMessage<FormationControlParams>);
	
	vFormationControlParams.def_property("action",
	    [](const FormationControlParams &x){return static_cast<FormationControlParams::ActionEnum>(x.action);},
	    [](FormationControlParams *x, const uint8_t &y){x->action = y;},
	    "");
	vFormationControlParams.def_readwrite("lon_gain", &FormationControlParams::lon_gain);
	vFormationControlParams.def_readwrite("lat_gain", &FormationControlParams::lat_gain);
	vFormationControlParams.def_readwrite("bond_thick", &FormationControlParams::bond_thick);
	vFormationControlParams.def_readwrite("lead_gain", &FormationControlParams::lead_gain);
	vFormationControlParams.def_readwrite("deconfl_gain", &FormationControlParams::deconfl_gain);
	vFormationControlParams.def_readwrite("accel_switch_gain", &FormationControlParams::accel_switch_gain);
	vFormationControlParams.def_readwrite("safe_dist", &FormationControlParams::safe_dist);
	vFormationControlParams.def_readwrite("deconflict_offset", &FormationControlParams::deconflict_offset);
	vFormationControlParams.def_readwrite("accel_safe_margin", &FormationControlParams::accel_safe_margin);
	vFormationControlParams.def_readwrite("accel_lim_x", &FormationControlParams::accel_lim_x);

	py::enum_<FormationControlParams::ActionEnum>(vFormationControlParams, "ActionEnum", "Action")
		.value("REQ", FormationControlParams::ActionEnum::OP_REQ)
		.value("SET", FormationControlParams::ActionEnum::OP_SET)
		.value("REP", FormationControlParams::ActionEnum::OP_REP);
}