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

void pbRowsCoverage(py::module &m) {
	auto vRowsCoverage = py::class_<RowsCoverage, Maneuver>(m, "RowsCoverage", "Rows Coverage");
	vRowsCoverage.def(py::init<>());
	vRowsCoverage.def("__setstate__", &pbUnpickleMessage<RowsCoverage>);
	vRowsCoverage.def_readwrite("lat", &RowsCoverage::lat);
	vRowsCoverage.def_readwrite("lon", &RowsCoverage::lon);
	vRowsCoverage.def_readwrite("z", &RowsCoverage::z);
	
	vRowsCoverage.def_property("z_units",
	    [](const RowsCoverage &x){return static_cast<ZUnits>(x.z_units);},
	    [](RowsCoverage *x, const uint8_t &y){x->z_units = y;},
	    "");
	vRowsCoverage.def_readwrite("speed", &RowsCoverage::speed);
	
	vRowsCoverage.def_property("speed_units",
	    [](const RowsCoverage &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](RowsCoverage *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vRowsCoverage.def_readwrite("bearing", &RowsCoverage::bearing);
	vRowsCoverage.def_readwrite("cross_angle", &RowsCoverage::cross_angle);
	vRowsCoverage.def_readwrite("width", &RowsCoverage::width);
	vRowsCoverage.def_readwrite("length", &RowsCoverage::length);
	vRowsCoverage.def_readwrite("coff", &RowsCoverage::coff);
	vRowsCoverage.def_readwrite("angaperture", &RowsCoverage::angaperture);
	vRowsCoverage.def_readwrite("range", &RowsCoverage::range);
	vRowsCoverage.def_readwrite("overlap", &RowsCoverage::overlap);
	vRowsCoverage.def_readwrite("flags", &RowsCoverage::flags);
	
	vRowsCoverage.def_property("custom",
	    [](const RowsCoverage &x){return ascii_to_unicode_safe(x.custom);},
	    [](RowsCoverage &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<RowsCoverage::FlagsBits>(vRowsCoverage, "FlagsBits", "Flags", py::arithmetic())
		.value("SQUARE_CURVE", RowsCoverage::FlagsBits::FLG_SQUARE_CURVE)
		.value("CURVE_RIGHT", RowsCoverage::FlagsBits::FLG_CURVE_RIGHT);
}