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

void pbPlanDBState(py::module &m) {
	auto vPlanDBState = py::class_<PlanDBState, Message>(m, "PlanDBState", "Plan DB State");
	vPlanDBState.def(py::init<>());
	vPlanDBState.def("__setstate__", &pbUnpickleMessage<PlanDBState>);
	vPlanDBState.def_readwrite("plan_count", &PlanDBState::plan_count);
	vPlanDBState.def_readwrite("plan_size", &PlanDBState::plan_size);
	vPlanDBState.def_readwrite("change_time", &PlanDBState::change_time);
	vPlanDBState.def_readwrite("change_sid", &PlanDBState::change_sid);
	
	vPlanDBState.def_property("change_sname",
	    [](const PlanDBState &x){return ascii_to_unicode_safe(x.change_sname);},
	    [](PlanDBState &x, std::string &s){x.change_sname = s;}, py::return_value_policy::take_ownership);
	
	vPlanDBState.def_property("md5",
	    [](const PlanDBState &x){return py::bytes(x.md5.data(), x.md5.size());},
	    [](PlanDBState &x, py::bytes &b){bytes_to_vector(b, x.md5);}, py::return_value_policy::take_ownership);
	vPlanDBState.def_readwrite("plans_info", &PlanDBState::plans_info);
}