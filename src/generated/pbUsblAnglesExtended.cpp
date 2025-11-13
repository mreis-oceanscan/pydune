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

void pbUsblAnglesExtended(py::module &m) {
	auto vUsblAnglesExtended = py::class_<UsblAnglesExtended, Message>(m, "UsblAnglesExtended", "USBL Angles Extended");
	vUsblAnglesExtended.def(py::init<>());
	vUsblAnglesExtended.def("__setstate__", &pbUnpickleMessage<UsblAnglesExtended>);
	
	vUsblAnglesExtended.def_property("target",
	    [](const UsblAnglesExtended &x){return ascii_to_unicode_safe(x.target);},
	    [](UsblAnglesExtended &x, std::string &s){x.target = s;}, py::return_value_policy::take_ownership);
	vUsblAnglesExtended.def_readwrite("lbearing", &UsblAnglesExtended::lbearing);
	vUsblAnglesExtended.def_readwrite("lelevation", &UsblAnglesExtended::lelevation);
	vUsblAnglesExtended.def_readwrite("bearing", &UsblAnglesExtended::bearing);
	vUsblAnglesExtended.def_readwrite("elevation", &UsblAnglesExtended::elevation);
	vUsblAnglesExtended.def_readwrite("phi", &UsblAnglesExtended::phi);
	vUsblAnglesExtended.def_readwrite("theta", &UsblAnglesExtended::theta);
	vUsblAnglesExtended.def_readwrite("psi", &UsblAnglesExtended::psi);
	vUsblAnglesExtended.def_readwrite("accuracy", &UsblAnglesExtended::accuracy);
}