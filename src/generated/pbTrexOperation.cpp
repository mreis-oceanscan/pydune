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

void pbTrexOperation(py::module &m) {
	auto vTrexOperation = py::class_<TrexOperation, Message>(m, "TrexOperation", "TREX Operation");
	vTrexOperation.def(py::init<>());
	vTrexOperation.def("__setstate__", &pbUnpickleMessage<TrexOperation>);
	
	vTrexOperation.def_property("op",
	    [](const TrexOperation &x){return static_cast<TrexOperation::OperationEnum>(x.op);},
	    [](TrexOperation *x, const uint8_t &y){x->op = y;},
	    "");
	
	vTrexOperation.def_property("goal_id",
	    [](const TrexOperation &x){return ascii_to_unicode_safe(x.goal_id);},
	    [](TrexOperation &x, std::string &s){x.goal_id = s;}, py::return_value_policy::take_ownership);
	
	vTrexOperation.def_property("token",
	[](const TrexOperation &x){return x.token.isNull() ? nullptr : x.token.get();},
	[](TrexOperation *x, const py::handle &y){
	    if(y.is_none()){
	        x->token.clear();
	    } else {
	        try {
	            x->token.set(y.cast<TrexToken*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are TrexToken or NoneType.");
	        }
	        x->token.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<TrexOperation::OperationEnum>(vTrexOperation, "OperationEnum", "Operation")
		.value("POST_TOKEN", TrexOperation::OperationEnum::OP_POST_TOKEN)
		.value("POST_GOAL", TrexOperation::OperationEnum::OP_POST_GOAL)
		.value("RECALL_GOAL", TrexOperation::OperationEnum::OP_RECALL_GOAL)
		.value("REQUEST_PLAN", TrexOperation::OperationEnum::OP_REQUEST_PLAN)
		.value("REPORT_PLAN", TrexOperation::OperationEnum::OP_REPORT_PLAN);
}