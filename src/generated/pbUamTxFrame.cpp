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

void pbUamTxFrame(py::module &m) {
	auto vUamTxFrame = py::class_<UamTxFrame, Message>(m, "UamTxFrame", "UamTxFrame");
	vUamTxFrame.def(py::init<>());
	vUamTxFrame.def("__setstate__", &pbUnpickleMessage<UamTxFrame>);
	vUamTxFrame.def_readwrite("seq", &UamTxFrame::seq);
	
	vUamTxFrame.def_property("sys_dst",
	    [](const UamTxFrame &x){return ascii_to_unicode_safe(x.sys_dst);},
	    [](UamTxFrame &x, std::string &s){x.sys_dst = s;}, py::return_value_policy::take_ownership);
	vUamTxFrame.def_readwrite("flags", &UamTxFrame::flags);
	
	vUamTxFrame.def_property("data",
	    [](const UamTxFrame &x){return py::bytes(x.data.data(), x.data.size());},
	    [](UamTxFrame &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);

	py::enum_<UamTxFrame::FlagsBits>(vUamTxFrame, "FlagsBits", "Flags", py::arithmetic())
		.value("ACK", UamTxFrame::FlagsBits::UTF_ACK)
		.value("DELAYED", UamTxFrame::FlagsBits::UTF_DELAYED)
		.value("FORCED", UamTxFrame::FlagsBits::UTF_FORCED);
}