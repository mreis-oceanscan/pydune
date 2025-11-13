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

void pbFormationMonitor(py::module &m) {
	auto vFormationMonitor = py::class_<FormationMonitor, Message>(m, "FormationMonitor", "Formation Monitoring Data");
	vFormationMonitor.def(py::init<>());
	vFormationMonitor.def("__setstate__", &pbUnpickleMessage<FormationMonitor>);
	vFormationMonitor.def_readwrite("ax_cmd", &FormationMonitor::ax_cmd);
	vFormationMonitor.def_readwrite("ay_cmd", &FormationMonitor::ay_cmd);
	vFormationMonitor.def_readwrite("az_cmd", &FormationMonitor::az_cmd);
	vFormationMonitor.def_readwrite("ax_des", &FormationMonitor::ax_des);
	vFormationMonitor.def_readwrite("ay_des", &FormationMonitor::ay_des);
	vFormationMonitor.def_readwrite("az_des", &FormationMonitor::az_des);
	vFormationMonitor.def_readwrite("virt_err_x", &FormationMonitor::virt_err_x);
	vFormationMonitor.def_readwrite("virt_err_y", &FormationMonitor::virt_err_y);
	vFormationMonitor.def_readwrite("virt_err_z", &FormationMonitor::virt_err_z);
	vFormationMonitor.def_readwrite("surf_fdbk_x", &FormationMonitor::surf_fdbk_x);
	vFormationMonitor.def_readwrite("surf_fdbk_y", &FormationMonitor::surf_fdbk_y);
	vFormationMonitor.def_readwrite("surf_fdbk_z", &FormationMonitor::surf_fdbk_z);
	vFormationMonitor.def_readwrite("surf_unkn_x", &FormationMonitor::surf_unkn_x);
	vFormationMonitor.def_readwrite("surf_unkn_y", &FormationMonitor::surf_unkn_y);
	vFormationMonitor.def_readwrite("surf_unkn_z", &FormationMonitor::surf_unkn_z);
	vFormationMonitor.def_readwrite("ss_x", &FormationMonitor::ss_x);
	vFormationMonitor.def_readwrite("ss_y", &FormationMonitor::ss_y);
	vFormationMonitor.def_readwrite("ss_z", &FormationMonitor::ss_z);
	vFormationMonitor.def_readwrite("rel_state", &FormationMonitor::rel_state);
}