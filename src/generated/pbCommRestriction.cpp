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

void pbCommRestriction(py::module &m) {
	auto vCommRestriction = py::class_<CommRestriction, Message>(m, "CommRestriction", "Communication Restriction");
	vCommRestriction.def(py::init<>());
	vCommRestriction.def("__setstate__", &pbUnpickleMessage<CommRestriction>);
	vCommRestriction.def_readwrite("restriction", &CommRestriction::restriction);
	
	vCommRestriction.def_property("reason",
	    [](const CommRestriction &x){return ascii_to_unicode_safe(x.reason);},
	    [](CommRestriction &x, std::string &s){x.reason = s;}, py::return_value_policy::take_ownership);

	py::enum_<CommRestriction::RestrictedCommunicationMeansBits>(vCommRestriction, "RestrictedCommunicationMeansBits", "Restricted Communication Means", py::arithmetic())
		.value("SATELLITE", CommRestriction::RestrictedCommunicationMeansBits::MEAN_SATELLITE)
		.value("ACOUSTIC", CommRestriction::RestrictedCommunicationMeansBits::MEAN_ACOUSTIC)
		.value("WIFI", CommRestriction::RestrictedCommunicationMeansBits::MEAN_WIFI)
		.value("GSM", CommRestriction::RestrictedCommunicationMeansBits::MEAN_GSM);
}