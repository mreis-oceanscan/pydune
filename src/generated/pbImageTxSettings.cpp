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

void pbImageTxSettings(py::module &m) {
	auto vImageTxSettings = py::class_<ImageTxSettings, Message>(m, "ImageTxSettings", "Image Transmission Settings");
	vImageTxSettings.def(py::init<>());
	vImageTxSettings.def("__setstate__", &pbUnpickleMessage<ImageTxSettings>);
	vImageTxSettings.def_readwrite("fps", &ImageTxSettings::fps);
	vImageTxSettings.def_readwrite("quality", &ImageTxSettings::quality);
	vImageTxSettings.def_readwrite("reps", &ImageTxSettings::reps);
	vImageTxSettings.def_readwrite("tsize", &ImageTxSettings::tsize);
}