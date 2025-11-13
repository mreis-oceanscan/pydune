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

void pbPlanDBInformation(py::module &m) {
	auto vPlanDBInformation = py::class_<PlanDBInformation, Message>(m, "PlanDBInformation", "Plan DB Information");
	vPlanDBInformation.def(py::init<>());
	vPlanDBInformation.def("__setstate__", &pbUnpickleMessage<PlanDBInformation>);
	
	vPlanDBInformation.def_property("plan_id",
	    [](const PlanDBInformation &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanDBInformation &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	vPlanDBInformation.def_readwrite("plan_size", &PlanDBInformation::plan_size);
	vPlanDBInformation.def_readwrite("change_time", &PlanDBInformation::change_time);
	vPlanDBInformation.def_readwrite("change_sid", &PlanDBInformation::change_sid);
	
	vPlanDBInformation.def_property("change_sname",
	    [](const PlanDBInformation &x){return ascii_to_unicode_safe(x.change_sname);},
	    [](PlanDBInformation &x, std::string &s){x.change_sname = s;}, py::return_value_policy::take_ownership);
	
	vPlanDBInformation.def_property("md5",
	    [](const PlanDBInformation &x){return py::bytes(x.md5.data(), x.md5.size());},
	    [](PlanDBInformation &x, py::bytes &b){bytes_to_vector(b, x.md5);}, py::return_value_policy::take_ownership);
}