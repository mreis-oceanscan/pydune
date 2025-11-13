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

void pbLblConfig(py::module &m) {
	auto vLblConfig = py::class_<LblConfig, Message>(m, "LblConfig", "LBL Configuration");
	vLblConfig.def(py::init<>());
	vLblConfig.def("__setstate__", &pbUnpickleMessage<LblConfig>);
	
	vLblConfig.def_property("op",
	    [](const LblConfig &x){return static_cast<LblConfig::OperationEnum>(x.op);},
	    [](LblConfig *x, const uint8_t &y){x->op = y;},
	    "");
	vLblConfig.def_readwrite("beacons", &LblConfig::beacons);

	py::enum_<LblConfig::OperationEnum>(vLblConfig, "OperationEnum", "Operation")
		.value("SET_CFG", LblConfig::OperationEnum::OP_SET_CFG)
		.value("GET_CFG", LblConfig::OperationEnum::OP_GET_CFG)
		.value("CUR_CFG", LblConfig::OperationEnum::OP_CUR_CFG);
}