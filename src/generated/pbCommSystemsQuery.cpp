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

void pbCommSystemsQuery(py::module &m) {
	auto vCommSystemsQuery = py::class_<CommSystemsQuery, Message>(m, "CommSystemsQuery", "Communication Systems Query");
	vCommSystemsQuery.def(py::init<>());
	vCommSystemsQuery.def("__setstate__", &pbUnpickleMessage<CommSystemsQuery>);
	vCommSystemsQuery.def_readwrite("type", &CommSystemsQuery::type);
	vCommSystemsQuery.def_readwrite("comm_interface", &CommSystemsQuery::comm_interface);
	
	vCommSystemsQuery.def_property("model",
	    [](const CommSystemsQuery &x){return static_cast<CommSystemsQuery::ModelEnum>(x.model);},
	    [](CommSystemsQuery *x, const uint16_t &y){x->model = y;},
	    "");
	
	vCommSystemsQuery.def_property("list",
	    [](const CommSystemsQuery &x){return ascii_to_unicode_safe(x.list);},
	    [](CommSystemsQuery &x, std::string &s){x.list = s;}, py::return_value_policy::take_ownership);

	py::enum_<CommSystemsQuery::TypeBits>(vCommSystemsQuery, "TypeBits", "Type", py::arithmetic())
		.value("QUERY", CommSystemsQuery::TypeBits::CIQ_QUERY)
		.value("REPLY", CommSystemsQuery::TypeBits::CIQ_REPLY);

	py::enum_<CommSystemsQuery::CommunicationInterfaceBits>(vCommSystemsQuery, "CommunicationInterfaceBits", "Communication Interface", py::arithmetic())
		.value("ACOUSTIC", CommSystemsQuery::CommunicationInterfaceBits::CIQ_ACOUSTIC)
		.value("SATELLITE", CommSystemsQuery::CommunicationInterfaceBits::CIQ_SATELLITE)
		.value("GSM", CommSystemsQuery::CommunicationInterfaceBits::CIQ_GSM)
		.value("MOBILE", CommSystemsQuery::CommunicationInterfaceBits::CIQ_MOBILE)
		.value("RADIO", CommSystemsQuery::CommunicationInterfaceBits::CIQ_RADIO);

	py::enum_<CommSystemsQuery::ModelEnum>(vCommSystemsQuery, "ModelEnum", "Model")
		.value("UNKNOWN", CommSystemsQuery::ModelEnum::CIQ_UNKNOWN)
		.value("M3DR", CommSystemsQuery::ModelEnum::CIQ_M3DR)
		.value("RDFXXXXPTP", CommSystemsQuery::ModelEnum::CIQ_RDFXXXXPTP);
}