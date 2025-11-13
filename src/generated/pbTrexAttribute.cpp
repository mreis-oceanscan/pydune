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

void pbTrexAttribute(py::module &m) {
	auto vTrexAttribute = py::class_<TrexAttribute, Message>(m, "TrexAttribute", "TREX Attribute");
	vTrexAttribute.def(py::init<>());
	vTrexAttribute.def("__setstate__", &pbUnpickleMessage<TrexAttribute>);
	
	vTrexAttribute.def_property("name",
	    [](const TrexAttribute &x){return ascii_to_unicode_safe(x.name);},
	    [](TrexAttribute &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vTrexAttribute.def_property("attr_type",
	    [](const TrexAttribute &x){return static_cast<TrexAttribute::AttributetypeEnum>(x.attr_type);},
	    [](TrexAttribute *x, const uint8_t &y){x->attr_type = y;},
	    "");
	
	vTrexAttribute.def_property("min",
	    [](const TrexAttribute &x){return ascii_to_unicode_safe(x.min);},
	    [](TrexAttribute &x, std::string &s){x.min = s;}, py::return_value_policy::take_ownership);
	
	vTrexAttribute.def_property("max",
	    [](const TrexAttribute &x){return ascii_to_unicode_safe(x.max);},
	    [](TrexAttribute &x, std::string &s){x.max = s;}, py::return_value_policy::take_ownership);

	py::enum_<TrexAttribute::AttributetypeEnum>(vTrexAttribute, "AttributeTypeEnum", "Attribute type")
		.value("BOOL", TrexAttribute::AttributetypeEnum::TYPE_BOOL)
		.value("INT", TrexAttribute::AttributetypeEnum::TYPE_INT)
		.value("FLOAT", TrexAttribute::AttributetypeEnum::TYPE_FLOAT)
		.value("STRING", TrexAttribute::AttributetypeEnum::TYPE_STRING)
		.value("ENUM", TrexAttribute::AttributetypeEnum::TYPE_ENUM);
}