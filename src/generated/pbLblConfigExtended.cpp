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

void pbLblConfigExtended(py::module &m) {
	auto vLblConfigExtended = py::class_<LblConfigExtended, Message>(m, "LblConfigExtended", "LBL Configuration Extended");
	vLblConfigExtended.def(py::init<>());
	vLblConfigExtended.def("__setstate__", &pbUnpickleMessage<LblConfigExtended>);
	
	vLblConfigExtended.def_property("op",
	    [](const LblConfigExtended &x){return static_cast<LblConfigExtended::OperationEnum>(x.op);},
	    [](LblConfigExtended *x, const uint8_t &y){x->op = y;},
	    "");
	vLblConfigExtended.def_readwrite("beacons", &LblConfigExtended::beacons);

	py::enum_<LblConfigExtended::OperationEnum>(vLblConfigExtended, "OperationEnum", "Operation")
		.value("SET_CFG", LblConfigExtended::OperationEnum::OP_SET_CFG)
		.value("GET_CFG", LblConfigExtended::OperationEnum::OP_GET_CFG)
		.value("CUR_CFG", LblConfigExtended::OperationEnum::OP_CUR_CFG)
		.value("POS_CFG", LblConfigExtended::OperationEnum::OP_POS_CFG);
}