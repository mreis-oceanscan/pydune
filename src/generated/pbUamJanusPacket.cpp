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

void pbUamJanusPacket(py::module &m) {
	auto vUamJanusPacket = py::class_<UamJanusPacket, Message>(m, "UamJanusPacket", "UamJanusPacket");
	vUamJanusPacket.def(py::init<>());
	vUamJanusPacket.def("__setstate__", &pbUnpickleMessage<UamJanusPacket>);
	vUamJanusPacket.def_readwrite("seq", &UamJanusPacket::seq);
	
	vUamJanusPacket.def_property("op",
	    [](const UamJanusPacket &x){return static_cast<UamJanusPacket::OperationEnum>(x.op);},
	    [](UamJanusPacket *x, const uint8_t &y){x->op = y;},
	    "");
	vUamJanusPacket.def_readwrite("baseline_flags", &UamJanusPacket::baseline_flags);
	vUamJanusPacket.def_readwrite("time", &UamJanusPacket::time);
	vUamJanusPacket.def_readwrite("class_user_id", &UamJanusPacket::class_user_id);
	vUamJanusPacket.def_readwrite("application_type", &UamJanusPacket::application_type);
	
	vUamJanusPacket.def_property("adb",
	    [](const UamJanusPacket &x){return py::bytes(x.adb.data(), x.adb.size());},
	    [](UamJanusPacket &x, py::bytes &b){bytes_to_vector(b, x.adb);}, py::return_value_policy::take_ownership);
	
	vUamJanusPacket.def_property("error",
	    [](const UamJanusPacket &x){return ascii_to_unicode_safe(x.error);},
	    [](UamJanusPacket &x, std::string &s){x.error = s;}, py::return_value_policy::take_ownership);
	vUamJanusPacket.def_readwrite("length", &UamJanusPacket::length);
	
	vUamJanusPacket.def_property("cargo",
	    [](const UamJanusPacket &x){return py::bytes(x.cargo.data(), x.cargo.size());},
	    [](UamJanusPacket &x, py::bytes &b){bytes_to_vector(b, x.cargo);}, py::return_value_policy::take_ownership);

	py::enum_<UamJanusPacket::OperationEnum>(vUamJanusPacket, "OperationEnum", "Operation")
		.value("SEND_REQ", UamJanusPacket::OperationEnum::OP_SEND_REQ)
		.value("BASELINE_RECV", UamJanusPacket::OperationEnum::OP_BASELINE_RECV)
		.value("UNPACK_REQ", UamJanusPacket::OperationEnum::OP_UNPACK_REQ)
		.value("UNPACK_REPLY", UamJanusPacket::OperationEnum::OP_UNPACK_REPLY)
		.value("UNPACK_ERROR", UamJanusPacket::OperationEnum::OP_UNPACK_ERROR)
		.value("SEND_SUCCESS", UamJanusPacket::OperationEnum::OP_SEND_SUCCESS)
		.value("SEND_ERROR", UamJanusPacket::OperationEnum::OP_SEND_ERROR);

	py::enum_<UamJanusPacket::BaselinePacketFlagsBits>(vUamJanusPacket, "BaselinePacketFlagsBits", "Baseline Packet Flags", py::arithmetic())
		.value("MOBILE", UamJanusPacket::BaselinePacketFlagsBits::JANUSBL_MOBILE)
		.value("REPEAT_INTERVAL", UamJanusPacket::BaselinePacketFlagsBits::JANUSBL_REPEAT_INTERVAL)
		.value("RESERVATION_TIME", UamJanusPacket::BaselinePacketFlagsBits::JANUSBL_RESERVATION_TIME)
		.value("DECODE_CAPABILITY", UamJanusPacket::BaselinePacketFlagsBits::JANUSBL_DECODE_CAPABILITY)
		.value("FORWARD_CAPABILITY", UamJanusPacket::BaselinePacketFlagsBits::JANUSBL_FORWARD_CAPABILITY);
}