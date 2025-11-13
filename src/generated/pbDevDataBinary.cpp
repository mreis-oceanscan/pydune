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

void pbDevDataBinary(py::module &m) {
	auto vDevDataBinary = py::class_<DevDataBinary, Message>(m, "DevDataBinary", "Device Data (Binary)");
	vDevDataBinary.def(py::init<>());
	vDevDataBinary.def("__setstate__", &pbUnpickleMessage<DevDataBinary>);
	
	vDevDataBinary.def_property("value",
	    [](const DevDataBinary &x){return py::bytes(x.value.data(), x.value.size());},
	    [](DevDataBinary &x, py::bytes &b){bytes_to_vector(b, x.value);}, py::return_value_policy::take_ownership);
}