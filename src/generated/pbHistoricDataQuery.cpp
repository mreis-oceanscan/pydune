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

void pbHistoricDataQuery(py::module &m) {
	auto vHistoricDataQuery = py::class_<HistoricDataQuery, Message>(m, "HistoricDataQuery", "Historic Data Query");
	vHistoricDataQuery.def(py::init<>());
	vHistoricDataQuery.def("__setstate__", &pbUnpickleMessage<HistoricDataQuery>);
	vHistoricDataQuery.def_readwrite("req_id", &HistoricDataQuery::req_id);
	
	vHistoricDataQuery.def_property("type",
	    [](const HistoricDataQuery &x){return static_cast<HistoricDataQuery::RequestTypeEnum>(x.type);},
	    [](HistoricDataQuery *x, const uint8_t &y){x->type = y;},
	    "");
	vHistoricDataQuery.def_readwrite("max_size", &HistoricDataQuery::max_size);
	
	vHistoricDataQuery.def_property("data",
	[](const HistoricDataQuery &x){return x.data.isNull() ? nullptr : x.data.get();},
	[](HistoricDataQuery *x, const py::handle &y){
	    if(y.is_none()){
	        x->data.clear();
	    } else {
	        try {
	            x->data.set(y.cast<HistoricData*>());
	        }
	        catch(const py::cast_error &e){
	            PyErr_Clear();
	            throw py::cast_error("Failed to cast to C++ type. Expected types are HistoricData or NoneType.");
	        }
	        x->data.setParent(x);
	    }
	}, py::keep_alive<1, 2>());

	py::enum_<HistoricDataQuery::RequestTypeEnum>(vHistoricDataQuery, "RequestTypeEnum", "Request Type")
		.value("QUERY", HistoricDataQuery::RequestTypeEnum::HRTYPE_QUERY)
		.value("REPLY", HistoricDataQuery::RequestTypeEnum::HRTYPE_REPLY)
		.value("CLEAR", HistoricDataQuery::RequestTypeEnum::HRTYPE_CLEAR);
}