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

void pbLowLevelControl(py::module &m) {
	auto vLowLevelControl = py::class_<LowLevelControl, Maneuver>(m, "LowLevelControl", "Low Level Control Maneuver");
	vLowLevelControl.def(py::init<>());
	vLowLevelControl.def("__setstate__", &pbUnpickleMessage<LowLevelControl>);
	
	vLowLevelControl.def_property("control",
	[](const LowLevelControl &x){return x.control.isNull() ? nullptr : x.control.get();},
	[](LowLevelControl *x, const py::handle &y){
	    if(y.is_none()){
	        x->control.clear();
	    } else {
	        try {
	            x->control.set(y.cast<ControlCommand*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are ControlCommand or NoneType.");
	        }
	        x->control.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	vLowLevelControl.def_readwrite("duration", &LowLevelControl::duration);
	
	vLowLevelControl.def_property("custom",
	    [](const LowLevelControl &x){return ascii_to_unicode_safe(x.custom);},
	    [](LowLevelControl &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);
}