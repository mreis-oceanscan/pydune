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

void pbUsblPositionExtended(py::module &m) {
	auto vUsblPositionExtended = py::class_<UsblPositionExtended, Message>(m, "UsblPositionExtended", "USBL Position Extended");
	vUsblPositionExtended.def(py::init<>());
	vUsblPositionExtended.def("__setstate__", &pbUnpickleMessage<UsblPositionExtended>);
	
	vUsblPositionExtended.def_property("target",
	    [](const UsblPositionExtended &x){return ascii_to_unicode_safe(x.target);},
	    [](UsblPositionExtended &x, std::string &s){x.target = s;}, py::return_value_policy::take_ownership);
	vUsblPositionExtended.def_readwrite("x", &UsblPositionExtended::x);
	vUsblPositionExtended.def_readwrite("y", &UsblPositionExtended::y);
	vUsblPositionExtended.def_readwrite("z", &UsblPositionExtended::z);
	vUsblPositionExtended.def_readwrite("n", &UsblPositionExtended::n);
	vUsblPositionExtended.def_readwrite("e", &UsblPositionExtended::e);
	vUsblPositionExtended.def_readwrite("d", &UsblPositionExtended::d);
	vUsblPositionExtended.def_readwrite("phi", &UsblPositionExtended::phi);
	vUsblPositionExtended.def_readwrite("theta", &UsblPositionExtended::theta);
	vUsblPositionExtended.def_readwrite("psi", &UsblPositionExtended::psi);
	vUsblPositionExtended.def_readwrite("accuracy", &UsblPositionExtended::accuracy);
}