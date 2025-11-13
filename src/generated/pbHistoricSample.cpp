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

void pbHistoricSample(py::module &m) {
	auto vHistoricSample = py::class_<HistoricSample, RemoteData>(m, "HistoricSample", "Historic Data Sample");
	vHistoricSample.def(py::init<>());
	vHistoricSample.def("__setstate__", &pbUnpickleMessage<HistoricSample>);
	vHistoricSample.def_readwrite("sys_id", &HistoricSample::sys_id);
	vHistoricSample.def_readwrite("priority", &HistoricSample::priority);
	vHistoricSample.def_readwrite("x", &HistoricSample::x);
	vHistoricSample.def_readwrite("y", &HistoricSample::y);
	vHistoricSample.def_readwrite("z", &HistoricSample::z);
	vHistoricSample.def_readwrite("t", &HistoricSample::t);
	
	vHistoricSample.def_property("sample",
	[](const HistoricSample &x){return x.sample.isNull() ? nullptr : x.sample.get();},
	[](HistoricSample *x, const py::handle &y){
	    if(y.is_none()){
	        x->sample.clear();
	    } else {
	        try {
	            x->sample.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->sample.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
}