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

void pbSimAcousticMessage(py::module &m) {
	auto vSimAcousticMessage = py::class_<SimAcousticMessage, Message>(m, "SimAcousticMessage", "Simulated Acoustic Message");
	vSimAcousticMessage.def(py::init<>());
	vSimAcousticMessage.def("__setstate__", &pbUnpickleMessage<SimAcousticMessage>);
	vSimAcousticMessage.def_readwrite("lat", &SimAcousticMessage::lat);
	vSimAcousticMessage.def_readwrite("lon", &SimAcousticMessage::lon);
	vSimAcousticMessage.def_readwrite("depth", &SimAcousticMessage::depth);
	
	vSimAcousticMessage.def_property("sentence",
	    [](const SimAcousticMessage &x){return ascii_to_unicode_safe(x.sentence);},
	    [](SimAcousticMessage &x, std::string &s){x.sentence = s;}, py::return_value_policy::take_ownership);
	vSimAcousticMessage.def_readwrite("txtime", &SimAcousticMessage::txtime);
	
	vSimAcousticMessage.def_property("modem_type",
	    [](const SimAcousticMessage &x){return ascii_to_unicode_safe(x.modem_type);},
	    [](SimAcousticMessage &x, std::string &s){x.modem_type = s;}, py::return_value_policy::take_ownership);
	
	vSimAcousticMessage.def_property("sys_src",
	    [](const SimAcousticMessage &x){return ascii_to_unicode_safe(x.sys_src);},
	    [](SimAcousticMessage &x, std::string &s){x.sys_src = s;}, py::return_value_policy::take_ownership);
	vSimAcousticMessage.def_readwrite("seq", &SimAcousticMessage::seq);
	
	vSimAcousticMessage.def_property("sys_dst",
	    [](const SimAcousticMessage &x){return ascii_to_unicode_safe(x.sys_dst);},
	    [](SimAcousticMessage &x, std::string &s){x.sys_dst = s;}, py::return_value_policy::take_ownership);
	vSimAcousticMessage.def_readwrite("flags", &SimAcousticMessage::flags);
	
	vSimAcousticMessage.def_property("data",
	    [](const SimAcousticMessage &x){return py::bytes(x.data.data(), x.data.size());},
	    [](SimAcousticMessage &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);

	py::enum_<SimAcousticMessage::FlagsBits>(vSimAcousticMessage, "FlagsBits", "Flags", py::arithmetic())
		.value("ACK", SimAcousticMessage::FlagsBits::SAM_ACK)
		.value("DELAYED", SimAcousticMessage::FlagsBits::SAM_DELAYED)
		.value("REPLY", SimAcousticMessage::FlagsBits::SAM_REPLY);
}