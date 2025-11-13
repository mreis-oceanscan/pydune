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

void pbAnnounceService(py::module &m) {
	auto vAnnounceService = py::class_<AnnounceService, Message>(m, "AnnounceService", "Announce Service");
	vAnnounceService.def(py::init<>());
	vAnnounceService.def("__setstate__", &pbUnpickleMessage<AnnounceService>);
	
	vAnnounceService.def_property("service",
	    [](const AnnounceService &x){return ascii_to_unicode_safe(x.service);},
	    [](AnnounceService &x, std::string &s){x.service = s;}, py::return_value_policy::take_ownership);
	vAnnounceService.def_readwrite("service_type", &AnnounceService::service_type);

	py::enum_<AnnounceService::ServiceTypeBits>(vAnnounceService, "ServicetypeBits", "ServiceType", py::arithmetic())
		.value("EXTERNAL", AnnounceService::ServiceTypeBits::SRV_TYPE_EXTERNAL)
		.value("LOCAL", AnnounceService::ServiceTypeBits::SRV_TYPE_LOCAL);
}