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

void pbUamRxFrame(py::module &m) {
	auto vUamRxFrame = py::class_<UamRxFrame, Message>(m, "UamRxFrame", "UamRxFrame");
	vUamRxFrame.def(py::init<>());
	vUamRxFrame.def("__setstate__", &pbUnpickleMessage<UamRxFrame>);
	
	vUamRxFrame.def_property("sys_src",
	    [](const UamRxFrame &x){return ascii_to_unicode_safe(x.sys_src);},
	    [](UamRxFrame &x, std::string &s){x.sys_src = s;}, py::return_value_policy::take_ownership);
	
	vUamRxFrame.def_property("sys_dst",
	    [](const UamRxFrame &x){return ascii_to_unicode_safe(x.sys_dst);},
	    [](UamRxFrame &x, std::string &s){x.sys_dst = s;}, py::return_value_policy::take_ownership);
	vUamRxFrame.def_readwrite("flags", &UamRxFrame::flags);
	
	vUamRxFrame.def_property("data",
	    [](const UamRxFrame &x){return py::bytes(x.data.data(), x.data.size());},
	    [](UamRxFrame &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);

	py::enum_<UamRxFrame::FlagsBits>(vUamRxFrame, "FlagsBits", "Flags", py::arithmetic())
		.value("PROMISCUOUS", UamRxFrame::FlagsBits::URF_PROMISCUOUS)
		.value("DELAYED", UamRxFrame::FlagsBits::URF_DELAYED);
}