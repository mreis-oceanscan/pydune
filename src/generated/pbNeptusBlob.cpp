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

void pbNeptusBlob(py::module &m) {
	auto vNeptusBlob = py::class_<NeptusBlob, Message>(m, "NeptusBlob", "Neptus Blob");
	vNeptusBlob.def(py::init<>());
	vNeptusBlob.def("__setstate__", &pbUnpickleMessage<NeptusBlob>);
	
	vNeptusBlob.def_property("content_type",
	    [](const NeptusBlob &x){return ascii_to_unicode_safe(x.content_type);},
	    [](NeptusBlob &x, std::string &s){x.content_type = s;}, py::return_value_policy::take_ownership);
	
	vNeptusBlob.def_property("content",
	    [](const NeptusBlob &x){return py::bytes(x.content.data(), x.content.size());},
	    [](NeptusBlob &x, py::bytes &b){bytes_to_vector(b, x.content);}, py::return_value_policy::take_ownership);
}