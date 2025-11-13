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

void pbCameraZoom(py::module &m) {
	auto vCameraZoom = py::class_<CameraZoom, Message>(m, "CameraZoom", "Camera Zoom");
	vCameraZoom.def(py::init<>());
	vCameraZoom.def("__setstate__", &pbUnpickleMessage<CameraZoom>);
	vCameraZoom.def_readwrite("id", &CameraZoom::id);
	vCameraZoom.def_readwrite("zoom", &CameraZoom::zoom);
	
	vCameraZoom.def_property("action",
	    [](const CameraZoom &x){return static_cast<CameraZoom::ActionEnum>(x.action);},
	    [](CameraZoom *x, const uint8_t &y){x->action = y;},
	    "");

	py::enum_<CameraZoom::ActionEnum>(vCameraZoom, "ActionEnum", "Action")
		.value("ZOOM_RESET", CameraZoom::ActionEnum::ACTION_ZOOM_RESET)
		.value("ZOOM_IN", CameraZoom::ActionEnum::ACTION_ZOOM_IN)
		.value("ZOOM_OUT", CameraZoom::ActionEnum::ACTION_ZOOM_OUT)
		.value("ZOOM_STOP", CameraZoom::ActionEnum::ACTION_ZOOM_STOP);
}