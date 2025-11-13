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

void pbTrexPlan(py::module &m) {
	auto vTrexPlan = py::class_<TrexPlan, Message>(m, "TrexPlan", "TREX Plan");
	vTrexPlan.def(py::init<>());
	vTrexPlan.def("__setstate__", &pbUnpickleMessage<TrexPlan>);
	
	vTrexPlan.def_property("reactor",
	    [](const TrexPlan &x){return ascii_to_unicode_safe(x.reactor);},
	    [](TrexPlan &x, std::string &s){x.reactor = s;}, py::return_value_policy::take_ownership);
	vTrexPlan.def_readwrite("tokens", &TrexPlan::tokens);
}