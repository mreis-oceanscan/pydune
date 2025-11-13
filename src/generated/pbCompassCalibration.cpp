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

void pbCompassCalibration(py::module &m) {
	auto vCompassCalibration = py::class_<CompassCalibration, Maneuver>(m, "CompassCalibration", "Compass Calibration Maneuver");
	vCompassCalibration.def(py::init<>());
	vCompassCalibration.def("__setstate__", &pbUnpickleMessage<CompassCalibration>);
	vCompassCalibration.def_readwrite("timeout", &CompassCalibration::timeout);
	vCompassCalibration.def_readwrite("lat", &CompassCalibration::lat);
	vCompassCalibration.def_readwrite("lon", &CompassCalibration::lon);
	vCompassCalibration.def_readwrite("z", &CompassCalibration::z);
	
	vCompassCalibration.def_property("z_units",
	    [](const CompassCalibration &x){return static_cast<ZUnits>(x.z_units);},
	    [](CompassCalibration *x, const uint8_t &y){x->z_units = y;},
	    "");
	vCompassCalibration.def_readwrite("pitch", &CompassCalibration::pitch);
	vCompassCalibration.def_readwrite("amplitude", &CompassCalibration::amplitude);
	vCompassCalibration.def_readwrite("duration", &CompassCalibration::duration);
	vCompassCalibration.def_readwrite("speed", &CompassCalibration::speed);
	
	vCompassCalibration.def_property("speed_units",
	    [](const CompassCalibration &x){return static_cast<SpeedUnits>(x.speed_units);},
	    [](CompassCalibration *x, const uint8_t &y){x->speed_units = y;},
	    "");
	vCompassCalibration.def_readwrite("radius", &CompassCalibration::radius);
	
	vCompassCalibration.def_property("direction",
	    [](const CompassCalibration &x){return static_cast<CompassCalibration::DirectionEnum>(x.direction);},
	    [](CompassCalibration *x, const uint8_t &y){x->direction = y;},
	    "");
	
	vCompassCalibration.def_property("custom",
	    [](const CompassCalibration &x){return ascii_to_unicode_safe(x.custom);},
	    [](CompassCalibration &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<CompassCalibration::DirectionEnum>(vCompassCalibration, "DirectionEnum", "Direction")
		.value("VDEP", CompassCalibration::DirectionEnum::LD_VDEP)
		.value("CLOCKW", CompassCalibration::DirectionEnum::LD_CLOCKW)
		.value("CCLOCKW", CompassCalibration::DirectionEnum::LD_CCLOCKW)
		.value("IWINDCURR", CompassCalibration::DirectionEnum::LD_IWINDCURR);
}