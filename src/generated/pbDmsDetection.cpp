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

void pbDmsDetection(py::module &m) {
	auto vDmsDetection = py::class_<DmsDetection, Message>(m, "DmsDetection", "DMS Detection");
	vDmsDetection.def(py::init<>());
	vDmsDetection.def("__setstate__", &pbUnpickleMessage<DmsDetection>);
	vDmsDetection.def_readwrite("ch01", &DmsDetection::ch01);
	vDmsDetection.def_readwrite("ch02", &DmsDetection::ch02);
	vDmsDetection.def_readwrite("ch03", &DmsDetection::ch03);
	vDmsDetection.def_readwrite("ch04", &DmsDetection::ch04);
	vDmsDetection.def_readwrite("ch05", &DmsDetection::ch05);
	vDmsDetection.def_readwrite("ch06", &DmsDetection::ch06);
	vDmsDetection.def_readwrite("ch07", &DmsDetection::ch07);
	vDmsDetection.def_readwrite("ch08", &DmsDetection::ch08);
	vDmsDetection.def_readwrite("ch09", &DmsDetection::ch09);
	vDmsDetection.def_readwrite("ch10", &DmsDetection::ch10);
	vDmsDetection.def_readwrite("ch11", &DmsDetection::ch11);
	vDmsDetection.def_readwrite("ch12", &DmsDetection::ch12);
	vDmsDetection.def_readwrite("ch13", &DmsDetection::ch13);
	vDmsDetection.def_readwrite("ch14", &DmsDetection::ch14);
	vDmsDetection.def_readwrite("ch15", &DmsDetection::ch15);
	vDmsDetection.def_readwrite("ch16", &DmsDetection::ch16);
}