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

void pbMsgList(py::module &m) {
	auto vMsgList = py::class_<MsgList, Message>(m, "MsgList", "Message List");
	vMsgList.def(py::init<>());
	vMsgList.def("__setstate__", &pbUnpickleMessage<MsgList>);
	vMsgList.def_readwrite("msgs", &MsgList::msgs);
}