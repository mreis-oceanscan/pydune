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

void pbTransmissionRequest(py::module &m) {
	auto vTransmissionRequest = py::class_<TransmissionRequest, Message>(m, "TransmissionRequest", "Transmission Request");
	vTransmissionRequest.def(py::init<>());
	vTransmissionRequest.def("__setstate__", &pbUnpickleMessage<TransmissionRequest>);
	vTransmissionRequest.def_readwrite("req_id", &TransmissionRequest::req_id);
	
	vTransmissionRequest.def_property("comm_mean",
	    [](const TransmissionRequest &x){return static_cast<TransmissionRequest::CommunicationMeanEnum>(x.comm_mean);},
	    [](TransmissionRequest *x, const uint8_t &y){x->comm_mean = y;},
	    "");
	
	vTransmissionRequest.def_property("destination",
	    [](const TransmissionRequest &x){return ascii_to_unicode_safe(x.destination);},
	    [](TransmissionRequest &x, std::string &s){x.destination = s;}, py::return_value_policy::take_ownership);
	vTransmissionRequest.def_readwrite("deadline", &TransmissionRequest::deadline);
	vTransmissionRequest.def_readwrite("range", &TransmissionRequest::range);
	
	vTransmissionRequest.def_property("data_mode",
	    [](const TransmissionRequest &x){return static_cast<TransmissionRequest::DataModeEnum>(x.data_mode);},
	    [](TransmissionRequest *x, const uint8_t &y){x->data_mode = y;},
	    "");
	
	vTransmissionRequest.def_property("msg_data",
	[](const TransmissionRequest &x){return x.msg_data.isNull() ? nullptr : x.msg_data.get();},
	[](TransmissionRequest *x, const py::handle &y){
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
	
	vTransmissionRequest.def_property("txt_data",
	    [](const TransmissionRequest &x){return ascii_to_unicode_safe(x.txt_data);},
	    [](TransmissionRequest &x, std::string &s){x.txt_data = s;}, py::return_value_policy::take_ownership);
	
	vTransmissionRequest.def_property("raw_data",
	    [](const TransmissionRequest &x){return py::bytes(x.raw_data.data(), x.raw_data.size());},
	    [](TransmissionRequest &x, py::bytes &b){bytes_to_vector(b, x.raw_data);}, py::return_value_policy::take_ownership);

	py::enum_<TransmissionRequest::CommunicationMeanEnum>(vTransmissionRequest, "CommunicationMeanEnum", "Communication Mean")
		.value("WIFI", TransmissionRequest::CommunicationMeanEnum::CMEAN_WIFI)
		.value("ACOUSTIC", TransmissionRequest::CommunicationMeanEnum::CMEAN_ACOUSTIC)
		.value("SATELLITE", TransmissionRequest::CommunicationMeanEnum::CMEAN_SATELLITE)
		.value("GSM", TransmissionRequest::CommunicationMeanEnum::CMEAN_GSM)
		.value("ANY", TransmissionRequest::CommunicationMeanEnum::CMEAN_ANY)
		.value("ALL", TransmissionRequest::CommunicationMeanEnum::CMEAN_ALL);

	py::enum_<TransmissionRequest::DataModeEnum>(vTransmissionRequest, "DataModeEnum", "Data Mode")
		.value("INLINEMSG", TransmissionRequest::DataModeEnum::DMODE_INLINEMSG)
		.value("TEXT", TransmissionRequest::DataModeEnum::DMODE_TEXT)
		.value("RAW", TransmissionRequest::DataModeEnum::DMODE_RAW)
		.value("ABORT", TransmissionRequest::DataModeEnum::DMODE_ABORT)
		.value("RANGE", TransmissionRequest::DataModeEnum::DMODE_RANGE)
		.value("REVERSE_RANGE", TransmissionRequest::DataModeEnum::DMODE_REVERSE_RANGE);
}