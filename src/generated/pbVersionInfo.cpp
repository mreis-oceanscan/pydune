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

void pbVersionInfo(py::module &m) {
	auto vVersionInfo = py::class_<VersionInfo, Message>(m, "VersionInfo", "Version Info");
	vVersionInfo.def(py::init<>());
	vVersionInfo.def("__setstate__", &pbUnpickleMessage<VersionInfo>);
	
	vVersionInfo.def_property("op",
	    [](const VersionInfo &x){return static_cast<VersionInfo::OperationEnum>(x.op);},
	    [](VersionInfo *x, const uint8_t &y){x->op = y;},
	    "");
	
	vVersionInfo.def_property("version",
	    [](const VersionInfo &x){return ascii_to_unicode_safe(x.version);},
	    [](VersionInfo &x, std::string &s){x.version = s;}, py::return_value_policy::take_ownership);
	
	vVersionInfo.def_property("description",
	    [](const VersionInfo &x){return ascii_to_unicode_safe(x.description);},
	    [](VersionInfo &x, std::string &s){x.description = s;}, py::return_value_policy::take_ownership);

	py::enum_<VersionInfo::OperationEnum>(vVersionInfo, "OperationEnum", "Operation")
		.value("REPLY", VersionInfo::OperationEnum::OP_REPLY)
		.value("QUERY", VersionInfo::OperationEnum::OP_QUERY);
}