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

void pbNavigationUncertainty(py::module &m) {
	auto vNavigationUncertainty = py::class_<NavigationUncertainty, Message>(m, "NavigationUncertainty", "Navigation Uncertainty");
	vNavigationUncertainty.def(py::init<>());
	vNavigationUncertainty.def("__setstate__", &pbUnpickleMessage<NavigationUncertainty>);
	vNavigationUncertainty.def_readwrite("x", &NavigationUncertainty::x);
	vNavigationUncertainty.def_readwrite("y", &NavigationUncertainty::y);
	vNavigationUncertainty.def_readwrite("z", &NavigationUncertainty::z);
	vNavigationUncertainty.def_readwrite("phi", &NavigationUncertainty::phi);
	vNavigationUncertainty.def_readwrite("theta", &NavigationUncertainty::theta);
	vNavigationUncertainty.def_readwrite("psi", &NavigationUncertainty::psi);
	vNavigationUncertainty.def_readwrite("p", &NavigationUncertainty::p);
	vNavigationUncertainty.def_readwrite("q", &NavigationUncertainty::q);
	vNavigationUncertainty.def_readwrite("r", &NavigationUncertainty::r);
	vNavigationUncertainty.def_readwrite("u", &NavigationUncertainty::u);
	vNavigationUncertainty.def_readwrite("v", &NavigationUncertainty::v);
	vNavigationUncertainty.def_readwrite("w", &NavigationUncertainty::w);
	vNavigationUncertainty.def_readwrite("bias_psi", &NavigationUncertainty::bias_psi);
	vNavigationUncertainty.def_readwrite("bias_r", &NavigationUncertainty::bias_r);
}