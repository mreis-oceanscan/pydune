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

void pbRestartSystem(py::module &m) {
	auto vRestartSystem = py::class_<RestartSystem, Message>(m, "RestartSystem", "Restart System");
	vRestartSystem.def(py::init<>());
	vRestartSystem.def("__setstate__", &pbUnpickleMessage<RestartSystem>);
	
	vRestartSystem.def_property("type",
	    [](const RestartSystem &x){return static_cast<RestartSystem::RestartTypeEnum>(x.type);},
	    [](RestartSystem *x, const uint8_t &y){x->type = y;},
	    "");

	py::enum_<RestartSystem::RestartTypeEnum>(vRestartSystem, "RestartTypeEnum", "Restart Type")
		.value("DUNE", RestartSystem::RestartTypeEnum::RSTYPE_DUNE)
		.value("SYSTEM", RestartSystem::RestartTypeEnum::RSTYPE_SYSTEM)
		.value("TASK", RestartSystem::RestartTypeEnum::RSTYPE_TASK);
}