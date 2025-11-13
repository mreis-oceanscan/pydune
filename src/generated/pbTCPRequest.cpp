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

void pbTCPRequest(py::module &m) {
	auto vTCPRequest = py::class_<TCPRequest, Message>(m, "TCPRequest", "TCP Transmission Request");
	vTCPRequest.def(py::init<>());
	vTCPRequest.def("__setstate__", &pbUnpickleMessage<TCPRequest>);
	vTCPRequest.def_readwrite("req_id", &TCPRequest::req_id);
	
	vTCPRequest.def_property("destination",
	    [](const TCPRequest &x){return ascii_to_unicode_safe(x.destination);},
	    [](TCPRequest &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	vTCPRequest.def_readwrite("timeout", &TCPRequest::timeout);
	
	vTCPRequest.def_property("msg_data",
	[](const TCPRequest &x){return x.msg_data.isNull() ? nullptr : x.msg_data.get();},
	[](TCPRequest *x, const py::handle &y){
	    if(y.is_none()){
	        x->msg_data.clear();
	    } else {
	        try {
	            x->msg_data.set(y.cast<Message*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are Message or NoneType.");
	        }
	        x->msg_data.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
}