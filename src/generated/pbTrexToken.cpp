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

void pbTrexToken(py::module &m) {
	auto vTrexToken = py::class_<TrexToken, Message>(m, "TrexToken", "TREX Token");
	vTrexToken.def(py::init<>());
	vTrexToken.def("__setstate__", &pbUnpickleMessage<TrexToken>);
	
	vTrexToken.def_property("timeline",
	    [](const TrexToken &x){return ascii_to_unicode_safe(x.timeline);},
	    [](TrexToken &x, std::string &s){x.timeline = s;}, py::return_value_policy::take_ownership);
	
	vTrexToken.def_property("predicate",
	    [](const TrexToken &x){return ascii_to_unicode_safe(x.predicate);},
	    [](TrexToken &x, std::string &s){x.predicate = s;}, py::return_value_policy::take_ownership);
	vTrexToken.def_readwrite("attributes", &TrexToken::attributes);
}