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

void pbUamTxStatus(py::module &m) {
	auto vUamTxStatus = py::class_<UamTxStatus, Message>(m, "UamTxStatus", "UamTxStatus");
	vUamTxStatus.def(py::init<>());
	vUamTxStatus.def("__setstate__", &pbUnpickleMessage<UamTxStatus>);
	vUamTxStatus.def_readwrite("seq", &UamTxStatus::seq);
	
	vUamTxStatus.def_property("value",
	    [](const UamTxStatus &x){return static_cast<UamTxStatus::ValueEnum>(x.value);},
	    [](UamTxStatus *x, const uint8_t &y){x->value = y;},
	    "");
	
	vUamTxStatus.def_property("error",
	    [](const UamTxStatus &x){return ascii_to_unicode_safe(x.error);},
	    [](UamTxStatus &x, std::string &s){x.error = s;}, py::return_value_policy::take_ownership);

	py::enum_<UamTxStatus::ValueEnum>(vUamTxStatus, "ValueEnum", "Value")
		.value("DONE", UamTxStatus::ValueEnum::UTS_DONE)
		.value("FAILED", UamTxStatus::ValueEnum::UTS_FAILED)
		.value("CANCELED", UamTxStatus::ValueEnum::UTS_CANCELED)
		.value("BUSY", UamTxStatus::ValueEnum::UTS_BUSY)
		.value("INV_ADDR", UamTxStatus::ValueEnum::UTS_INV_ADDR)
		.value("IP", UamTxStatus::ValueEnum::UTS_IP)
		.value("UNSUPPORTED", UamTxStatus::ValueEnum::UTS_UNSUPPORTED)
		.value("INV_SIZE", UamTxStatus::ValueEnum::UTS_INV_SIZE)
		.value("SENT", UamTxStatus::ValueEnum::UTS_SENT)
		.value("DELIVERED", UamTxStatus::ValueEnum::UTS_DELIVERED)
		.value("NO_TRANSDUCER", UamTxStatus::ValueEnum::UTS_NO_TRANSDUCER);
}