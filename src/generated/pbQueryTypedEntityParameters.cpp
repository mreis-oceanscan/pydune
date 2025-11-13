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

void pbQueryTypedEntityParameters(py::module &m) {
	auto vQueryTypedEntityParameters = py::class_<QueryTypedEntityParameters, Message>(m, "QueryTypedEntityParameters", "Query Typed Entity Parameters");
	vQueryTypedEntityParameters.def(py::init<>());
	vQueryTypedEntityParameters.def("__setstate__", &pbUnpickleMessage<QueryTypedEntityParameters>);
	
	vQueryTypedEntityParameters.def_property("op",
	    [](const QueryTypedEntityParameters &x){return static_cast<QueryTypedEntityParameters::OperationEnum>(x.op);},
	    [](QueryTypedEntityParameters *x, const uint8_t &y){x->op = y;},
	    "");
	vQueryTypedEntityParameters.def_readwrite("request_id", &QueryTypedEntityParameters::request_id);
	
	vQueryTypedEntityParameters.def_property("entity_name",
	    [](const QueryTypedEntityParameters &x){return ascii_to_unicode_safe(x.entity_name);},
	    [](QueryTypedEntityParameters &x, std::string &s){x.entity_name = s;}, py::return_value_policy::take_ownership);
	vQueryTypedEntityParameters.def_readwrite("parameters", &QueryTypedEntityParameters::parameters);

	py::enum_<QueryTypedEntityParameters::OperationEnum>(vQueryTypedEntityParameters, "OperationEnum", "Operation")
		.value("REQUEST", QueryTypedEntityParameters::OperationEnum::OP_REQUEST)
		.value("REPLY", QueryTypedEntityParameters::OperationEnum::OP_REPLY);
}