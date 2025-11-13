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

void pbLogBookEntry(py::module &m) {
	auto vLogBookEntry = py::class_<LogBookEntry, Message>(m, "LogBookEntry", "Log Book Entry");
	vLogBookEntry.def(py::init<>());
	vLogBookEntry.def("__setstate__", &pbUnpickleMessage<LogBookEntry>);
	
	vLogBookEntry.def_property("type",
	    [](const LogBookEntry &x){return static_cast<LogBookEntry::TypeEnum>(x.type);},
	    [](LogBookEntry *x, const uint8_t &y){x->type = y;},
	    "");
	vLogBookEntry.def_readwrite("htime", &LogBookEntry::htime);
	
	vLogBookEntry.def_property("context",
	    [](const LogBookEntry &x){return ascii_to_unicode_safe(x.context);},
	    [](LogBookEntry &x, std::string &s){x.context = s;}, py::return_value_policy::take_ownership);
	
	vLogBookEntry.def_property("text",
	    [](const LogBookEntry &x){return ascii_to_unicode_safe(x.text);},
	    [](LogBookEntry &x, std::string &s){x.text = s;}, py::return_value_policy::take_ownership);

	py::enum_<LogBookEntry::TypeEnum>(vLogBookEntry, "TypeEnum", "Type")
		.value("INFO", LogBookEntry::TypeEnum::LBET_INFO)
		.value("WARNING", LogBookEntry::TypeEnum::LBET_WARNING)
		.value("ERROR", LogBookEntry::TypeEnum::LBET_ERROR)
		.value("CRITICAL", LogBookEntry::TypeEnum::LBET_CRITICAL)
		.value("DEBUG", LogBookEntry::TypeEnum::LBET_DEBUG);
}