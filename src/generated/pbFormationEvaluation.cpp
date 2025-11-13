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

void pbFormationEvaluation(py::module &m) {
	auto vFormationEvaluation = py::class_<FormationEvaluation, Message>(m, "FormationEvaluation", "Formation Evaluation Data");
	vFormationEvaluation.def(py::init<>());
	vFormationEvaluation.def("__setstate__", &pbUnpickleMessage<FormationEvaluation>);
	
	vFormationEvaluation.def_property("type",
	    [](const FormationEvaluation &x){return static_cast<FormationEvaluation::TypeEnum>(x.type);},
	    [](FormationEvaluation *x, const uint8_t &y){x->type = y;},
	    "");
	
	vFormationEvaluation.def_property("op",
	    [](const FormationEvaluation &x){return static_cast<FormationEvaluation::OperationEnum>(x.op);},
	    [](FormationEvaluation *x, const uint8_t &y){x->op = y;},
	    "");
	vFormationEvaluation.def_readwrite("err_mean", &FormationEvaluation::err_mean);
	vFormationEvaluation.def_readwrite("dist_min_abs", &FormationEvaluation::dist_min_abs);
	vFormationEvaluation.def_readwrite("dist_min_mean", &FormationEvaluation::dist_min_mean);
	vFormationEvaluation.def_readwrite("roll_rate_mean", &FormationEvaluation::roll_rate_mean);
	vFormationEvaluation.def_readwrite("time", &FormationEvaluation::time);
	
	vFormationEvaluation.def_property("controlparams",
	[](const FormationEvaluation &x){return x.controlparams.isNull() ? nullptr : x.controlparams.get();},
	[](FormationEvaluation *x, const py::handle &y){
	    if(y.is_none()){
	        x->controlparams.clear();
	    } else {
	        try {
	            x->controlparams.set(y.cast<FormationControlParams*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are FormationControlParams or NoneType.");
	        }
	        x->controlparams.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<FormationEvaluation::TypeEnum>(vFormationEvaluation, "TypeEnum", "Type")
		.value("REQUEST", FormationEvaluation::TypeEnum::FC_REQUEST)
		.value("REPORT", FormationEvaluation::TypeEnum::FC_REPORT);

	py::enum_<FormationEvaluation::OperationEnum>(vFormationEvaluation, "OperationEnum", "Operation")
		.value("START", FormationEvaluation::OperationEnum::OP_START)
		.value("STOP", FormationEvaluation::OperationEnum::OP_STOP)
		.value("READY", FormationEvaluation::OperationEnum::OP_READY)
		.value("EXECUTING", FormationEvaluation::OperationEnum::OP_EXECUTING)
		.value("FAILURE", FormationEvaluation::OperationEnum::OP_FAILURE);
}