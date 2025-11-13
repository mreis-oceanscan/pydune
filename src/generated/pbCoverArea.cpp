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

void pbCoverArea(py::module &m) {
	auto vCoverArea = py::class_<CoverArea, Maneuver>(m, "CoverArea", "Cover Area");
	vCoverArea.def(py::init<>());
	vCoverArea.def("__setstate__", &pbUnpickleMessage<CoverArea>);
	vCoverArea.def_readwrite("lat", &CoverArea::lat);
	vCoverArea.def_readwrite("lon", &CoverArea::lon);
	vCoverArea.def_readwrite("z", &CoverArea::z);
	
	vCoverArea.def_property("z_units",
	    [](const CoverArea &x){return static_cast<ZUnits>(x.z_units);},
	    [](CoverArea *x, const uint8_t &y){x->z_units = y;},
	    "");
	vCoverArea.def_readwrite("speed", &CoverArea::speed);
	
	vCoverArea.def_property("speed_units",
	    [](const CoverArea &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](CoverArea *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vCoverArea.def_readwrite("polygon", &CoverArea::polygon);
	
	vCoverArea.def_property("custom",
	    [](const CoverArea &x){return ascii_to_unicode_safe(x.custom);},
	    [](CoverArea &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}