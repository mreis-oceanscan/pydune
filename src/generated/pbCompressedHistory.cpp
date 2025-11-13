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

void pbCompressedHistory(py::module &m) {
	auto vCompressedHistory = py::class_<CompressedHistory, Message>(m, "CompressedHistory", "Compressed Historic Data Series");
	vCompressedHistory.def(py::init<>());
	vCompressedHistory.def("__setstate__", &pbUnpickleMessage<CompressedHistory>);
	vCompressedHistory.def_readwrite("base_lat", &CompressedHistory::base_lat);
	vCompressedHistory.def_readwrite("base_lon", &CompressedHistory::base_lon);
	vCompressedHistory.def_readwrite("base_time", &CompressedHistory::base_time);
	
	vCompressedHistory.def_property("data",
	    [](const CompressedHistory &x){return py::bytes(x.data.data(), x.data.size());},
	    [](CompressedHistory &x, py::bytes &b){bytes_to_vector(b, x.data);}, py::return_value_policy::take_ownership);
}