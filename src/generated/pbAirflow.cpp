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

void pbAirflow(py::module &m) {
	auto vAirflow = py::class_<Airflow, Message>(m, "Airflow", "Airflow");
	vAirflow.def(py::init<>());
	vAirflow.def("__setstate__", &pbUnpickleMessage<Airflow>);
	vAirflow.def_readwrite("va", &Airflow::va);
	vAirflow.def_readwrite("aoa", &Airflow::aoa);
	vAirflow.def_readwrite("ssa", &Airflow::ssa);
}