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

void pbExternalNavData(py::module &m) {
	auto vExternalNavData = py::class_<ExternalNavData, Message>(m, "ExternalNavData", "External Navigation Data");
	vExternalNavData.def(py::init<>());
	vExternalNavData.def("__setstate__", &pbUnpickleMessage<ExternalNavData>);
	
	vExternalNavData.def_property("state",
	[](const ExternalNavData &x){return x.state.isNull() ? nullptr : x.state.get();},
	[](ExternalNavData *x, const py::handle &y){
	    if(y.is_none()){
	        x->state.clear();
	    } else {
	        try {
	            x->state.set(y.cast<EstimatedState*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are EstimatedState or NoneType.");
	        }
	        x->state.setParent(x);
	    }
	}, py::keep_alive<1, 2>());
	
	vExternalNavData.def_property("type",
	    [](const ExternalNavData &x){return static_cast<ExternalNavData::NavDataTypeEnum>(x.type);},
	    [](ExternalNavData *x, const uint8_t &y){x->type = y;},
	    "");

	py::enum_<ExternalNavData::NavDataTypeEnum>(vExternalNavData, "NavDataTypeEnum", "Nav Data Type")
		.value("FULL", ExternalNavData::NavDataTypeEnum::EXTNAV_FULL)
		.value("AHRS", ExternalNavData::NavDataTypeEnum::EXTNAV_AHRS)
		.value("POSREF", ExternalNavData::NavDataTypeEnum::EXTNAV_POSREF);
}