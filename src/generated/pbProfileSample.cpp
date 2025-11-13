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

void pbProfileSample(py::module &m) {
	auto vProfileSample = py::class_<ProfileSample, Message>(m, "ProfileSample", "Profile Sample");
	vProfileSample.def(py::init<>());
	vProfileSample.def("__setstate__", &pbUnpickleMessage<ProfileSample>);
	vProfileSample.def_readwrite("depth", &ProfileSample::depth);
	vProfileSample.def_readwrite("avg", &ProfileSample::avg);
}