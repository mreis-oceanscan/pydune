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

void pbFileSampleEvent(py::module &m) {
	auto vFileSampleEvent = py::class_<FileSampleEvent, Message>(m, "FileSampleEvent", "File Sample Event");
	vFileSampleEvent.def(py::init<>());
	vFileSampleEvent.def("__setstate__", &pbUnpickleMessage<FileSampleEvent>);
	
	vFileSampleEvent.def_property("fstype",
	    [](const FileSampleEvent &x){return static_cast<FileSampleEvent::FileTypeEnum>(x.fstype);},
	    [](FileSampleEvent *x, const uint8_t &y){x->fstype = y;},
	    "");
	
	vFileSampleEvent.def_property("filename",
	    [](const FileSampleEvent &x){return ascii_to_unicode_safe(x.filename);},
	    [](FileSampleEvent &x, std::string &s){x.filename = s;}, py::return_value_policy::take_ownership);

	py::enum_<FileSampleEvent::FileTypeEnum>(vFileSampleEvent, "FileTypeEnum", "File Type")
		.value("IMAGE", FileSampleEvent::FileTypeEnum::FSTYPE_IMAGE)
		.value("AUDIO", FileSampleEvent::FileTypeEnum::FSTYPE_AUDIO)
		.value("SONAR", FileSampleEvent::FileTypeEnum::FSTYPE_SONAR)
		.value("OTHER", FileSampleEvent::FileTypeEnum::FSTYPE_OTHER);
}