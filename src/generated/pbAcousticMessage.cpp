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

void pbAcousticMessage(py::module &m) {
	auto vAcousticMessage = py::class_<AcousticMessage, Message>(m, "AcousticMessage", "Acoustic Message");
	vAcousticMessage.def(py::init<>());
	vAcousticMessage.def("__setstate__", &pbUnpickleMessage<AcousticMessage>);
	
	vAcousticMessage.def_property("message",
	[](const AcousticMessage &x){return x.message.isNull() ? nullptr : x.message.get();},
	[](AcousticMessage *x, const py::handle &y){
	    if(y.is_none()){
	        x->message.clear();
	    } else {
	        try {
	            x->message.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->message.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
}