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

void pbQueryGsmCredit(py::module &m) {
	auto vQueryGsmCredit = py::class_<QueryGsmCredit, Message>(m, "QueryGsmCredit", "Query GSM Credit");
	vQueryGsmCredit.def(py::init<>());
	vQueryGsmCredit.def("__setstate__", &pbUnpickleMessage<QueryGsmCredit>);
	vQueryGsmCredit.def_readwrite("req_id", &QueryGsmCredit::req_id);
}