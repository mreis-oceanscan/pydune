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

void pbUsblConfig(py::module &m) {
	auto vUsblConfig = py::class_<UsblConfig, Message>(m, "UsblConfig", "USBL Configuration");
	vUsblConfig.def(py::init<>());
	vUsblConfig.def("__setstate__", &pbUnpickleMessage<UsblConfig>);
	
	vUsblConfig.def_property("op",
	    [](const UsblConfig &x){return static_cast<UsblConfig::OperationEnum>(x.op);},
	    [](UsblConfig *x, const uint8_t &y){x->op = y;},
	    "");
	vUsblConfig.def_readwrite("modems", &UsblConfig::modems);

	py::enum_<UsblConfig::OperationEnum>(vUsblConfig, "OperationEnum", "Operation")
		.value("SET_CFG", UsblConfig::OperationEnum::OP_SET_CFG)
		.value("GET_CFG", UsblConfig::OperationEnum::OP_GET_CFG)
		.value("CUR_CFG", UsblConfig::OperationEnum::OP_CUR_CFG);
}