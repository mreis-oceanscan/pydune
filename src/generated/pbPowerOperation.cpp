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

void pbPowerOperation(py::module &m) {
	auto vPowerOperation = py::class_<PowerOperation, Message>(m, "PowerOperation", "Power Operation");
	vPowerOperation.def(py::init<>());
	vPowerOperation.def("__setstate__", &pbUnpickleMessage<PowerOperation>);
	
	vPowerOperation.def_property("op",
	    [](const PowerOperation &x){return static_cast<PowerOperation::OperationEnum>(x.op);},
	    [](PowerOperation *x, const uint8_t &y){x->op = y;},
	    "");
	vPowerOperation.def_readwrite("time_remain", &PowerOperation::time_remain);
	vPowerOperation.def_readwrite("sched_time", &PowerOperation::sched_time);

	py::enum_<PowerOperation::OperationEnum>(vPowerOperation, "OperationEnum", "Operation")
		.value("PWR_DOWN", PowerOperation::OperationEnum::POP_PWR_DOWN)
		.value("PWR_DOWN_IP", PowerOperation::OperationEnum::POP_PWR_DOWN_IP)
		.value("PWR_DOWN_ABORTED", PowerOperation::OperationEnum::POP_PWR_DOWN_ABORTED)
		.value("SCHED_PWR_DOWN", PowerOperation::OperationEnum::POP_SCHED_PWR_DOWN)
		.value("PWR_UP", PowerOperation::OperationEnum::POP_PWR_UP)
		.value("PWR_UP_IP", PowerOperation::OperationEnum::POP_PWR_UP_IP)
		.value("SCHED_PWR_UP", PowerOperation::OperationEnum::POP_SCHED_PWR_UP);
}