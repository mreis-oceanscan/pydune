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

void pbRelativeState(py::module &m) {
	auto vRelativeState = py::class_<RelativeState, Message>(m, "RelativeState", "Relative State");
	vRelativeState.def(py::init<>());
	vRelativeState.def("__setstate__", &pbUnpickleMessage<RelativeState>);
	
	vRelativeState.def_property("s_id",
	    [](const RelativeState &x){return ascii_to_unicode_safe(x.s_id);},
	    [](RelativeState &x, std::string &s){x.s_id = s;}, py::return_value_policy::take_ownership);
	vRelativeState.def_readwrite("dist", &RelativeState::dist);
	vRelativeState.def_readwrite("err", &RelativeState::err);
	vRelativeState.def_readwrite("ctrl_imp", &RelativeState::ctrl_imp);
	vRelativeState.def_readwrite("rel_dir_x", &RelativeState::rel_dir_x);
	vRelativeState.def_readwrite("rel_dir_y", &RelativeState::rel_dir_y);
	vRelativeState.def_readwrite("rel_dir_z", &RelativeState::rel_dir_z);
	vRelativeState.def_readwrite("err_x", &RelativeState::err_x);
	vRelativeState.def_readwrite("err_y", &RelativeState::err_y);
	vRelativeState.def_readwrite("err_z", &RelativeState::err_z);
	vRelativeState.def_readwrite("rf_err_x", &RelativeState::rf_err_x);
	vRelativeState.def_readwrite("rf_err_y", &RelativeState::rf_err_y);
	vRelativeState.def_readwrite("rf_err_z", &RelativeState::rf_err_z);
	vRelativeState.def_readwrite("rf_err_vx", &RelativeState::rf_err_vx);
	vRelativeState.def_readwrite("rf_err_vy", &RelativeState::rf_err_vy);
	vRelativeState.def_readwrite("rf_err_vz", &RelativeState::rf_err_vz);
	vRelativeState.def_readwrite("ss_x", &RelativeState::ss_x);
	vRelativeState.def_readwrite("ss_y", &RelativeState::ss_y);
	vRelativeState.def_readwrite("ss_z", &RelativeState::ss_z);
	vRelativeState.def_readwrite("virt_err_x", &RelativeState::virt_err_x);
	vRelativeState.def_readwrite("virt_err_y", &RelativeState::virt_err_y);
	vRelativeState.def_readwrite("virt_err_z", &RelativeState::virt_err_z);
}