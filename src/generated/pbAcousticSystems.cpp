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

void pbAcousticSystems(py::module &m) {
	auto vAcousticSystems = py::class_<AcousticSystems, Message>(m, "AcousticSystems", "Acoustic Systems");
	vAcousticSystems.def(py::init<>());
	vAcousticSystems.def("__setstate__", &pbUnpickleMessage<AcousticSystems>);
	
	vAcousticSystems.def_property("list",
	    [](const AcousticSystems &x){return ascii_to_unicode_safe(x.list);},
	    [](AcousticSystems &x, std::string &s){x.list = s;}, py::return_value_policy::take_ownership);
}