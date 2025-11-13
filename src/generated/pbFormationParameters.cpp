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

void pbFormationParameters(py::module &m) {
	auto vFormationParameters = py::class_<FormationParameters, Message>(m, "FormationParameters", "Formation Parameters");
	vFormationParameters.def(py::init<>());
	vFormationParameters.def("__setstate__", &pbUnpickleMessage<FormationParameters>);
	
	vFormationParameters.def_property("formation_name",
	    [](const FormationParameters &x){return ascii_to_unicode_safe(x.formation_name);},
	    [](FormationParameters &x, std::string &s){x.formation_name = s;}, py::return_value_policy::take_ownership);
	
	vFormationParameters.def_property("reference_frame",
	    [](const FormationParameters &x){return static_cast<FormationParameters::FormationReferenceFrameEnum>(x.reference_frame);},
	    [](FormationParameters *x, const uint8_t &y){x->reference_frame = y;},
	    "");
	vFormationParameters.def_readwrite("participants", &FormationParameters::participants);
	
	vFormationParameters.def_property("custom",
	    [](const FormationParameters &x){return ascii_to_unicode_safe(x.custom);},
	    [](FormationParameters &x, std::string &s){x.custom = s;}, py::return_value_policy::take_ownership);

	py::enum_<FormationParameters::FormationReferenceFrameEnum>(vFormationParameters, "FormationReferenceFrameEnum", "Formation Reference Frame")
		.value("EARTH_FIXED", FormationParameters::FormationReferenceFrameEnum::OP_EARTH_FIXED)
		.value("PATH_FIXED", FormationParameters::FormationReferenceFrameEnum::OP_PATH_FIXED)
		.value("PATH_CURVED", FormationParameters::FormationReferenceFrameEnum::OP_PATH_CURVED);
}