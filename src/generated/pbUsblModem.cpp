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

void pbUsblModem(py::module &m) {
	auto vUsblModem = py::class_<UsblModem, Message>(m, "UsblModem", "USBL Modem Configuration");
	vUsblModem.def(py::init<>());
	vUsblModem.def("__setstate__", &pbUnpickleMessage<UsblModem>);
	
	vUsblModem.def_property("name",
	    [](const UsblModem &x){return ascii_to_unicode_safe(x.name);},
	    [](UsblModem &x, std::string &s){x.name = s;}, py::return_value_policy::take_ownership);
	vUsblModem.def_readwrite("lat", &UsblModem::lat);
	vUsblModem.def_readwrite("lon", &UsblModem::lon);
	vUsblModem.def_readwrite("z", &UsblModem::z);
	
	vUsblModem.def_property("z_units",
	    [](const UsblModem &x){return static_cast<ZUnits>(x.z_units);},
	    [](UsblModem *x, const uint8_t &y){x->z_units = y;},
	    "");
}