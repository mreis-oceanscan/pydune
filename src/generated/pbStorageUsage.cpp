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

void pbStorageUsage(py::module &m) {
	auto vStorageUsage = py::class_<StorageUsage, Message>(m, "StorageUsage", "Storage Usage");
	vStorageUsage.def(py::init<>());
	vStorageUsage.def("__setstate__", &pbUnpickleMessage<StorageUsage>);
	vStorageUsage.def_readwrite("available", &StorageUsage::available);
	vStorageUsage.def_readwrite("value", &StorageUsage::value);
}