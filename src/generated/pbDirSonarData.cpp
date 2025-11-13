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

void pbDirSonarData(py::module &m) {
	auto vDirSonarData = py::class_<DirSonarData, Message>(m, "DirSonarData", "Directional Sonar Data");
	vDirSonarData.def(py::init<>());
	vDirSonarData.def("__setstate__", &pbUnpickleMessage<DirSonarData>);
	
	vDirSonarData.def_property("pose",
	[](const DirSonarData &x){return x.pose.isNull() ? nullptr : x.pose.get();},
	[](DirSonarData *x, const py::handle &y){
	    if(y.is_none()){
	        x->pose.clear();
	    } else {
	        try {
	            x->pose.set(y.cast<DeviceState*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are DeviceState or NoneType.");
	        }
	        x->pose.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vDirSonarData.def_property("measurement",
	[](const DirSonarData &x){return x.measurement.isNull() ? nullptr : x.measurement.get();},
	[](DirSonarData *x, const py::handle &y){
	    if(y.is_none()){
	        x->measurement.clear();
	    } else {
	        try {
	            x->measurement.set(y.cast<SonarData*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are SonarData or NoneType.");
	        }
	        x->measurement.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
}