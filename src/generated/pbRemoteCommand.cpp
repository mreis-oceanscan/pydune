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

void pbRemoteCommand(py::module &m) {
	auto vRemoteCommand = py::class_<RemoteCommand, RemoteData>(m, "RemoteCommand", "Remote Command");
	vRemoteCommand.def(py::init<>());
	vRemoteCommand.def("__setstate__", &pbUnpickleMessage<RemoteCommand>);
	vRemoteCommand.def_readwrite("original_source", &RemoteCommand::original_source);
	vRemoteCommand.def_readwrite("destination", &RemoteCommand::destination);
	vRemoteCommand.def_readwrite("timeout", &RemoteCommand::timeout);
	
	vRemoteCommand.def_property("cmd",
	[](const RemoteCommand &x){return x.cmd.isNull() ? nullptr : x.cmd.get();},
	[](RemoteCommand *x, const py::handle &y){
	    if(y.is_none()){
	        x->cmd.clear();
	    } else {
	        try {
	            x->cmd.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->cmd.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
}