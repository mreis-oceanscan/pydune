#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <DUNE/IMC/Bitfields.hpp>
namespace py = pybind11;
using namespace DUNE::IMC;

void pbBitfields(py::module &m) {
	py::enum_<CLoopsMask>(m, "CLoopsMask", "Control Loops Mask", py::arithmetic())
		.value("NONE", CLoopsMask::CL_NONE)
		.value("PATH", CLoopsMask::CL_PATH)
		.value("TELEOPERATION", CLoopsMask::CL_TELEOPERATION)
		.value("ALTITUDE", CLoopsMask::CL_ALTITUDE)
		.value("DEPTH", CLoopsMask::CL_DEPTH)
		.value("ROLL", CLoopsMask::CL_ROLL)
		.value("PITCH", CLoopsMask::CL_PITCH)
		.value("YAW", CLoopsMask::CL_YAW)
		.value("SPEED", CLoopsMask::CL_SPEED)
		.value("YAW_RATE", CLoopsMask::CL_YAW_RATE)
		.value("VERTICAL_RATE", CLoopsMask::CL_VERTICAL_RATE)
		.value("TORQUE", CLoopsMask::CL_TORQUE)
		.value("FORCE", CLoopsMask::CL_FORCE)
		.value("VELOCITY", CLoopsMask::CL_VELOCITY)
		.value("THROTTLE", CLoopsMask::CL_THROTTLE)
		.value("HOVERING", CLoopsMask::CL_HOVERING)
		.value("EXTERNAL", CLoopsMask::CL_EXTERNAL)
		.value("NO_OVERRIDE", CLoopsMask::CL_NO_OVERRIDE)
		.value("ALL", CLoopsMask::CL_ALL);
	py::enum_<OpLimitsMask>(m, "OpLimitsMask", "Operational Limits Mask", py::arithmetic())
		.value("MAX_DEPTH", OpLimitsMask::OPL_MAX_DEPTH)
		.value("MIN_ALT", OpLimitsMask::OPL_MIN_ALT)
		.value("MAX_ALT", OpLimitsMask::OPL_MAX_ALT)
		.value("MIN_SPEED", OpLimitsMask::OPL_MIN_SPEED)
		.value("MAX_SPEED", OpLimitsMask::OPL_MAX_SPEED)
		.value("MAX_VRATE", OpLimitsMask::OPL_MAX_VRATE)
		.value("AREA", OpLimitsMask::OPL_AREA);
}
