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

void pbControlParcel(py::module &m) {
	auto vControlParcel = py::class_<ControlParcel, Message>(m, "ControlParcel", "Control Parcel");
	vControlParcel.def(py::init<>());
	vControlParcel.def("__setstate__", &pbUnpickleMessage<ControlParcel>);
	vControlParcel.def_readwrite("p", &ControlParcel::p);
	vControlParcel.def_readwrite("i", &ControlParcel::i);
	vControlParcel.def_readwrite("d", &ControlParcel::d);
	vControlParcel.def_readwrite("a", &ControlParcel::a);
}