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

void pbTrexObservation(py::module &m) {
	auto vTrexObservation = py::class_<TrexObservation, Message>(m, "TrexObservation", "TREX Observation");
	vTrexObservation.def(py::init<>());
	vTrexObservation.def("__setstate__", &pbUnpickleMessage<TrexObservation>);
	
	vTrexObservation.def_property("timeline",
	    [](const TrexObservation &x){return ascii_to_unicode_safe(x.timeline);},
	    [](TrexObservation &x, std::string &s){x.timeline = s;}, py::return_value_policy::take_ownership);
	
	vTrexObservation.def_property("predicate",
	    [](const TrexObservation &x){return ascii_to_unicode_safe(x.predicate);},
	    [](TrexObservation &x, std::string &s){x.predicate = s;}, py::return_value_policy::take_ownership);
	
	vTrexObservation.def_property("attributes",
	    [](const TrexObservation &x){return ascii_to_unicode_safe(x.attributes);},
	    [](TrexObservation &x, std::string &s){x.attributes = s;}, py::return_value_policy::take_ownership);
}