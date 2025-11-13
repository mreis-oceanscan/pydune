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

void pbEntityList(py::module &m) {
	auto vEntityList = py::class_<EntityList, Message>(m, "EntityList", "Entity List");
	vEntityList.def(py::init<>());
	vEntityList.def("__setstate__", &pbUnpickleMessage<EntityList>);
	
	vEntityList.def_property("op",
	    [](const EntityList &x){return static_cast<EntityList::operationEnum>(x.op);},
	    [](EntityList *x, const uint8_t &y){x->op = y;},
	    "");
	
	vEntityList.def_property("list",
	    [](const EntityList &x){return ascii_to_unicode_safe(x.list);},
	    [](EntityList &x, std::string &s){x.list = s;}, py::return_value_policy::take_ownership);

	py::enum_<EntityList::operationEnum>(vEntityList, "OperationEnum", "operation")
		.value("REPORT", EntityList::operationEnum::OP_REPORT)
		.value("QUERY", EntityList::operationEnum::OP_QUERY)
		.value("RELOAD", EntityList::operationEnum::OP_RELOAD);
}