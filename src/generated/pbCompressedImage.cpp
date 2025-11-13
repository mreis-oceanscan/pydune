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

void pbCompressedImage(py::module &m) {
	auto vCompressedImage = py::class_<CompressedImage, Message>(m, "CompressedImage", "Compressed Image");
	vCompressedImage.def(py::init<>());
	vCompressedImage.def("__setstate__", &pbUnpickleMessage<CompressedImage>);
	vCompressedImage.def_readwrite("frameid", &CompressedImage::frameid);
	
	vCompressedImage.def_property("data",
	    [](const CompressedImage &x){return py::bytes(x.data.data(), x.data.size());},
	    [](CompressedImage &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}