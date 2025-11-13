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

void pbFileClassification(py::module &m) {
	auto vFileClassification = py::class_<FileClassification, Message>(m, "FileClassification", "File Classification Event");
	vFileClassification.def(py::init<>());
	vFileClassification.def("__setstate__", &pbUnpickleMessage<FileClassification>);
	
	vFileClassification.def_property("original_filepath",
	    [](const FileClassification &x){return ascii_to_unicode_safe(x.original_filepath);},
	    [](FileClassification &x, std::string &s){x.original_filepath = s;}, py::return_value_policy::take_ownership);
	
	vFileClassification.def_property("resized_filepath",
	    [](const FileClassification &x){return ascii_to_unicode_safe(x.resized_filepath);},
	    [](FileClassification &x, std::string &s){x.resized_filepath = s;}, py::return_value_policy::take_ownership);
	
	vFileClassification.def_property("class_prediction",
	    [](const FileClassification &x){return ascii_to_unicode_safe(x.class_prediction);},
	    [](FileClassification &x, std::string &s){x.class_prediction = s;}, py::return_value_policy::take_ownership);
	vFileClassification.def_readwrite("confidence", &FileClassification::confidence);
	
	vFileClassification.def_property("fstype",
	    [](const FileClassification &x){return static_cast<FileClassification::FileTypeEnum>(x.fstype);},
	    [](FileClassification *x, const uint8_t &y){x->fstype = y;},
	    "");

	py::enum_<FileClassification::FileTypeEnum>(vFileClassification, "FileTypeEnum", "File Type")
		.value("IMAGE", FileClassification::FileTypeEnum::FSTYPE_IMAGE)
		.value("AUDIO", FileClassification::FileTypeEnum::FSTYPE_AUDIO)
		.value("SONAR", FileClassification::FileTypeEnum::FSTYPE_SONAR)
		.value("OTHER", FileClassification::FileTypeEnum::FSTYPE_OTHER);
}