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

void pbLblEstimate(py::module &m) {
	auto vLblEstimate = py::class_<LblEstimate, Message>(m, "LblEstimate", "LBL Beacon Position Estimate");
	vLblEstimate.def(py::init<>());
	vLblEstimate.def("__setstate__", &pbUnpickleMessage<LblEstimate>);
	
	vLblEstimate.def_property("beacon",
	[](const LblEstimate &x){return x.beacon.isNull() ? nullptr : x.beacon.get();},
	[](LblEstimate *x, const py::handle &y){
	    if(y.is_none()){
	        x->beacon.clear();
	    } else {
	        try {
	            x->beacon.set(y.cast<LblBeacon*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are LblBeacon or NoneType.");
	        }
	        x->beacon.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	vLblEstimate.def_readwrite("x", &LblEstimate::x);
	vLblEstimate.def_readwrite("y", &LblEstimate::y);
	vLblEstimate.def_readwrite("var_x", &LblEstimate::var_x);
	vLblEstimate.def_readwrite("var_y", &LblEstimate::var_y);
	vLblEstimate.def_readwrite("distance", &LblEstimate::distance);
}