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

void pbReference(py::module &m) {
	auto vReference = py::class_<Reference, Message>(m, "Reference", "Reference To Follow");
	vReference.def(py::init<>());
	vReference.def("__setstate__", &pbUnpickleMessage<Reference>);
	vReference.def_readwrite("flags", &Reference::flags);
	
	vReference.def_property("speed",
	[](const Reference &x){return x.speed.isNull() ? nullptr : x.speed.get();},
	[](Reference *x, const py::handle &y){
	    if(y.is_none()){
	        x->speed.clear();
	    } else {
	        try {
	            x->speed.set(y.cast<DesiredSpeed*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are DesiredSpeed or NoneType.");
	        }
	        x->speed.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vReference.def_property("z",
	[](const Reference &x){return x.z.isNull() ? nullptr : x.z.get();},
	[](Reference *x, const py::handle &y){
	    if(y.is_none()){
	        x->z.clear();
	    } else {
	        try {
	            x->z.set(y.cast<DesiredZ*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are DesiredZ or NoneType.");
	        }
	        x->z.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	vReference.def_readwrite("lat", &Reference::lat);
	vReference.def_readwrite("lon", &Reference::lon);
	vReference.def_readwrite("radius", &Reference::radius);

	py::enum_<Reference::FlagsBits>(vReference, "FlagsBits", "Flags", py::arithmetic())
		.value("LOCATION", Reference::FlagsBits::FLAG_LOCATION)
		.value("SPEED", Reference::FlagsBits::FLAG_SPEED)
		.value("Z", Reference::FlagsBits::FLAG_Z)
		.value("RADIUS", Reference::FlagsBits::FLAG_RADIUS)
		.value("START_POINT", Reference::FlagsBits::FLAG_START_POINT)
		.value("DIRECT", Reference::FlagsBits::FLAG_DIRECT)
		.value("MANDONE", Reference::FlagsBits::FLAG_MANDONE);
}