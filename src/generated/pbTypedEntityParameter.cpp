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

void pbTypedEntityParameter(py::module &m) {
	auto vTypedEntityParameter = py::class_<TypedEntityParameter, Message>(m, "TypedEntityParameter", "Typed Entity Parameter");
	vTypedEntityParameter.def(py::init<>());
	vTypedEntityParameter.def("__setstate__", &pbUnpickleMessage<TypedEntityParameter>);
	
	vTypedEntityParameter.def_property("name",
	    [](const TypedEntityParameter &x){return ascii_to_unicode_safe(x.name);},
	    [](TypedEntityParameter &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	
	vTypedEntityParameter.def_property("type",
	    [](const TypedEntityParameter &x){return static_cast<TypedEntityParameter::TypeEnum>(x.type);},
	    [](TypedEntityParameter *x, const uint8_t &y){x->type = y;},
	    "");
	
	vTypedEntityParameter.def_property("default_value",
	    [](const TypedEntityParameter &x){return ascii_to_unicode_safe(x.default_value);},
	    [](TypedEntityParameter &x, std::string &s){x.default_value = s;}, py::return_value_policy::take_ownership);
	
	vTypedEntityParameter.def_property("units",
	    [](const TypedEntityParameter &x){return ascii_to_unicode_safe(x.units);},
	    [](TypedEntityParameter &x, std::string &s){x.units = s;}, py::return_value_policy::take_ownership);
	
	vTypedEntityParameter.def_property("description",
	    [](const TypedEntityParameter &x){return ascii_to_unicode_safe(x.description);},
	    [](TypedEntityParameter &x, std::string &s){x.description = s;}, py::return_value_policy::take_ownership);
	
	vTypedEntityParameter.def_property("values_list",
	    [](const TypedEntityParameter &x){return ascii_to_unicode_safe(x.values_list);},
	    [](TypedEntityParameter &x, std::string &s){x.values_list = s;}, py::return_value_policy::take_ownership);
	vTypedEntityParameter.def_readwrite("min_value", &TypedEntityParameter::min_value);
	vTypedEntityParameter.def_readwrite("max_value", &TypedEntityParameter::max_value);
	vTypedEntityParameter.def_readwrite("list_min_size", &TypedEntityParameter::list_min_size);
	vTypedEntityParameter.def_readwrite("list_max_size", &TypedEntityParameter::list_max_size);
	vTypedEntityParameter.def_readwrite("values_if_list", &TypedEntityParameter::values_if_list);
	
	vTypedEntityParameter.def_property("visibility",
	    [](const TypedEntityParameter &x){return static_cast<TypedEntityParameter::VisibilityEnum>(x.visibility);},
	    [](TypedEntityParameter *x, const uint8_t &y){x->visibility = y;},
	    "");
	
	vTypedEntityParameter.def_property("scope",
	    [](const TypedEntityParameter &x){return static_cast<TypedEntityParameter::ScopeEnum>(x.scope);},
	    [](TypedEntityParameter *x, const uint8_t &y){x->scope = y;},
	    "");

	py::enum_<TypedEntityParameter::TypeEnum>(vTypedEntityParameter, "TypeEnum", "Type")
		.value("BOOL", TypedEntityParameter::TypeEnum::TYPE_BOOL)
		.value("INT", TypedEntityParameter::TypeEnum::TYPE_INT)
		.value("FLOAT", TypedEntityParameter::TypeEnum::TYPE_FLOAT)
		.value("STRING", TypedEntityParameter::TypeEnum::TYPE_STRING)
		.value("LIST_BOOL", TypedEntityParameter::TypeEnum::TYPE_LIST_BOOL)
		.value("LIST_INT", TypedEntityParameter::TypeEnum::TYPE_LIST_INT)
		.value("LIST_FLOAT", TypedEntityParameter::TypeEnum::TYPE_LIST_FLOAT)
		.value("LIST_STRING", TypedEntityParameter::TypeEnum::TYPE_LIST_STRING);

	py::enum_<TypedEntityParameter::VisibilityEnum>(vTypedEntityParameter, "VisibilityEnum", "Visibility")
		.value("USER", TypedEntityParameter::VisibilityEnum::VISIBILITY_USER)
		.value("DEVELOPER", TypedEntityParameter::VisibilityEnum::VISIBILITY_DEVELOPER);

	py::enum_<TypedEntityParameter::ScopeEnum>(vTypedEntityParameter, "ScopeEnum", "Scope")
		.value("GLOBAL", TypedEntityParameter::ScopeEnum::SCOPE_GLOBAL)
		.value("IDLE", TypedEntityParameter::ScopeEnum::SCOPE_IDLE)
		.value("PLAN", TypedEntityParameter::ScopeEnum::SCOPE_PLAN)
		.value("MANEUVER", TypedEntityParameter::ScopeEnum::SCOPE_MANEUVER);
}