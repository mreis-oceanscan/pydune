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

void pbPlanDB(py::module &m) {
	auto vPlanDB = py::class_<PlanDB, Message>(m, "PlanDB", "Plan DB");
	vPlanDB.def(py::init<>());
	vPlanDB.def("__setstate__", &pbUnpickleMessage<PlanDB>);
	
	vPlanDB.def_property("type",
	    [](const PlanDB &x){return static_cast<PlanDB::TypeEnum>(x.type);},
	    [](PlanDB *x, const uint8_t &y){x->type = y;},
	    "");
	
	vPlanDB.def_property("op",
	    [](const PlanDB &x){return static_cast<PlanDB::OperationEnum>(x.op);},
	    [](PlanDB *x, const uint8_t &y){x->op = y;},
	    "");
	vPlanDB.def_readwrite("request_id", &PlanDB::request_id);
	
	vPlanDB.def_property("plan_id",
	    [](const PlanDB &x){return ascii_to_unicode_safe(x.plan_id);},
	    [](PlanDB &x, std::string &s){x.plan_id = s;}, py::return_value_policy::take_ownership);
	
	vPlanDB.def_property("arg",
	[](const PlanDB &x){return x.arg.isNull() ? nullptr : x.arg.get();},
	[](PlanDB *x, const py::handle &y){
	    if(y.is_none()){
	        x->arg.clear();
	    } else {
	        try {
	            x->arg.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->arg.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vPlanDB.def_property("info",
	    [](const PlanDB &x){return ascii_to_unicode_safe(x.info);},
	    [](PlanDB &x, std::string &s){x.info = s;}, py::return_value_policy::take_ownership);

	py::enum_<PlanDB::TypeEnum>(vPlanDB, "TypeEnum", "Type")
		.value("REQUEST", PlanDB::TypeEnum::DBT_REQUEST)
		.value("SUCCESS", PlanDB::TypeEnum::DBT_SUCCESS)
		.value("FAILURE", PlanDB::TypeEnum::DBT_FAILURE)
		.value("IN_PROGRESS", PlanDB::TypeEnum::DBT_IN_PROGRESS);

	py::enum_<PlanDB::OperationEnum>(vPlanDB, "OperationEnum", "Operation")
		.value("SET", PlanDB::OperationEnum::DBOP_SET)
		.value("DEL", PlanDB::OperationEnum::DBOP_DEL)
		.value("GET", PlanDB::OperationEnum::DBOP_GET)
		.value("GET_INFO", PlanDB::OperationEnum::DBOP_GET_INFO)
		.value("CLEAR", PlanDB::OperationEnum::DBOP_CLEAR)
		.value("GET_STATE", PlanDB::OperationEnum::DBOP_GET_STATE)
		.value("GET_DSTATE", PlanDB::OperationEnum::DBOP_GET_DSTATE)
		.value("BOOT", PlanDB::OperationEnum::DBOP_BOOT);
}