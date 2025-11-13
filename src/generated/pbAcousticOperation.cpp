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

void pbAcousticOperation(py::module &m) {
	auto vAcousticOperation = py::class_<AcousticOperation, Message>(m, "AcousticOperation", "Acoustic Operation");
	vAcousticOperation.def(py::init<>());
	vAcousticOperation.def("__setstate__", &pbUnpickleMessage<AcousticOperation>);
	
	vAcousticOperation.def_property("op",
	    [](const AcousticOperation &x){return static_cast<AcousticOperation::OperationEnum>(x.op);},
	    [](AcousticOperation *x, const uint8_t &y){x->op = y;},
	    "");
	
	vAcousticOperation.def_property("system",
	    [](const AcousticOperation &x){return ascii_to_unicode_safe(x.system);},
	    [](AcousticOperation &x, std::string &s){x.system = s;}, py::return_value_policy::take_ownership);
	vAcousticOperation.def_readwrite("range", &AcousticOperation::range);
	
	vAcousticOperation.def_property("msg",
	[](const AcousticOperation &x){return x.msg.isNull() ? nullptr : x.msg.get();},
	[](AcousticOperation *x, const py::handle &y){
	    if(y.is_none()){
	        x->msg.clear();
	    } else {
	        try {
	            x->msg.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->msg.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<AcousticOperation::OperationEnum>(vAcousticOperation, "OperationEnum", "Operation")
		.value("ABORT", AcousticOperation::OperationEnum::AOP_ABORT)
		.value("ABORT_IP", AcousticOperation::OperationEnum::AOP_ABORT_IP)
		.value("ABORT_TIMEOUT", AcousticOperation::OperationEnum::AOP_ABORT_TIMEOUT)
		.value("ABORT_ACKED", AcousticOperation::OperationEnum::AOP_ABORT_ACKED)
		.value("RANGE", AcousticOperation::OperationEnum::AOP_RANGE)
		.value("RANGE_IP", AcousticOperation::OperationEnum::AOP_RANGE_IP)
		.value("RANGE_TIMEOUT", AcousticOperation::OperationEnum::AOP_RANGE_TIMEOUT)
		.value("RANGE_RECVED", AcousticOperation::OperationEnum::AOP_RANGE_RECVED)
		.value("BUSY", AcousticOperation::OperationEnum::AOP_BUSY)
		.value("UNSUPPORTED", AcousticOperation::OperationEnum::AOP_UNSUPPORTED)
		.value("NO_TXD", AcousticOperation::OperationEnum::AOP_NO_TXD)
		.value("MSG", AcousticOperation::OperationEnum::AOP_MSG)
		.value("MSG_QUEUED", AcousticOperation::OperationEnum::AOP_MSG_QUEUED)
		.value("MSG_IP", AcousticOperation::OperationEnum::AOP_MSG_IP)
		.value("MSG_DONE", AcousticOperation::OperationEnum::AOP_MSG_DONE)
		.value("MSG_FAILURE", AcousticOperation::OperationEnum::AOP_MSG_FAILURE)
		.value("MSG_SHORT", AcousticOperation::OperationEnum::AOP_MSG_SHORT)
		.value("REVERSE_RANGE", AcousticOperation::OperationEnum::AOP_REVERSE_RANGE)
		.value("FORCED_ABORT", AcousticOperation::OperationEnum::AOP_FORCED_ABORT)
		.value("MSG_FRAGMENT", AcousticOperation::OperationEnum::AOP_MSG_FRAGMENT);
}