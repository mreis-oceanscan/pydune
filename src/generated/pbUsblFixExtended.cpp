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

void pbUsblFixExtended(py::module &m) {
	auto vUsblFixExtended = py::class_<UsblFixExtended, Message>(m, "UsblFixExtended", "USBL Fix Extended");
	vUsblFixExtended.def(py::init<>());
	vUsblFixExtended.def("__setstate__", &pbUnpickleMessage<UsblFixExtended>);
	
	vUsblFixExtended.def_property("target",
	    [](const UsblFixExtended &x){return ascii_to_unicode_safe(x.target);},
	    [](UsblFixExtended &x, std::string &s){x.target = s;}, py::return_value_policy::take_ownership);
	vUsblFixExtended.def_readwrite("lat", &UsblFixExtended::lat);
	vUsblFixExtended.def_readwrite("lon", &UsblFixExtended::lon);
	
	vUsblFixExtended.def_property("z_units",
	    [](const UsblFixExtended &x){return static_cast<ZUnits>(x.z_units);},
	    [](UsblFixExtended *x, const uint8_t &y){x->z_units = y;},
	    "");
	vUsblFixExtended.def_readwrite("z", &UsblFixExtended::z);
	vUsblFixExtended.def_readwrite("accuracy", &UsblFixExtended::accuracy);
}