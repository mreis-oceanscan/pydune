#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <DUNE/IMC/SuperTypes.hpp>
namespace py = pybind11;
using namespace DUNE::IMC;

void pbSuperTypes(py::module &m) {
	py::class_<Maneuver, Message>(m, "Maneuver", "Super type Maneuver");
	py::class_<ControlCommand, Message>(m, "ControlCommand", "Super type ControlCommand");
	py::class_<RemoteData, Message>(m, "RemoteData", "Super type RemoteData");
}