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

void pbValuesIf(py::module &m) {
	auto vValuesIf = py::class_<ValuesIf, Message>(m, "ValuesIf", "Values If");
	vValuesIf.def(py::init<>());
	vValuesIf.def("__setstate__", &pbUnpickleMessage<ValuesIf>);
	
	vValuesIf.def_property("param",
	    [](const ValuesIf &x){return ascii_to_unicode_safe(x.param);},
	    [](ValuesIf &x, std::string &s){x.param = s;}, py::return_value_policy::take_ownership);
	
	vValuesIf.def_property("value",
	    [](const ValuesIf &x){return ascii_to_unicode_safe(x.value);},
	    [](ValuesIf &x, std::string &s){x.value = s;}, py::return_value_policy::take_ownership);
	
	vValuesIf.def_property("values_list",
	    [](const ValuesIf &x){return ascii_to_unicode_safe(x.values_list);},
	    [](ValuesIf &x, std::string &s){x.values_list = s;}, py::return_value_policy::take_ownership);
}