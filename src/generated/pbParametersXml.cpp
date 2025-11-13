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

void pbParametersXml(py::module &m) {
	auto vParametersXml = py::class_<ParametersXml, Message>(m, "ParametersXml", "Parameters XML");
	vParametersXml.def(py::init<>());
	vParametersXml.def("__setstate__", &pbUnpickleMessage<ParametersXml>);
	
	vParametersXml.def_property("locale",
	    [](const ParametersXml &x){return ascii_to_unicode_safe(x.locale);},
	    [](ParametersXml &x, std::string &s){x.locale = s;}, py::return_value_policy::take_ownership);
	
	vParametersXml.def_property("config",
	    [](const ParametersXml &x){return py::bytes(x.config.data(), x.config.size());},
	    [](ParametersXml &x, py::bytes &b){bytes_to_vector(b, x.config);}, py::return_value_policy::take_ownership);
}