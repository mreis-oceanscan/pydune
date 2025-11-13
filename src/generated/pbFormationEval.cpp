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

void pbFormationEval(py::module &m) {
	auto vFormationEval = py::class_<FormationEval, Message>(m, "FormationEval", "Formation Evaluation Data");
	vFormationEval.def(py::init<>());
	vFormationEval.def("__setstate__", &pbUnpickleMessage<FormationEval>);
	vFormationEval.def_readwrite("err_mean", &FormationEval::err_mean);
	vFormationEval.def_readwrite("dist_min_abs", &FormationEval::dist_min_abs);
	vFormationEval.def_readwrite("dist_min_mean", &FormationEval::dist_min_mean);
}