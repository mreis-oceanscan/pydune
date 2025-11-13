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

void pbUsblFix(py::module &m) {
	auto vUsblFix = py::class_<UsblFix, Message>(m, "UsblFix", "USBL Fix");
	vUsblFix.def(py::init<>());
	vUsblFix.def("__setstate__", &pbUnpickleMessage<UsblFix>);
	vUsblFix.def_readwrite("target", &UsblFix::target);
	vUsblFix.def_readwrite("lat", &UsblFix::lat);
	vUsblFix.def_readwrite("lon", &UsblFix::lon);
	
	vUsblFix.def_property("z_units",
	    [](const UsblFix &x){return static_cast<ZUnits>(x.z_units);},
	    [](UsblFix *x, const uint8_t &y){x->z_units = y;},
	    "");
	vUsblFix.def_readwrite("z", &UsblFix::z);
}