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

void pbWaveSpectrumParameters(py::module &m) {
	auto vWaveSpectrumParameters = py::class_<WaveSpectrumParameters, Message>(m, "WaveSpectrumParameters", "Wave Spectrum Parameters");
	vWaveSpectrumParameters.def(py::init<>());
	vWaveSpectrumParameters.def("__setstate__", &pbUnpickleMessage<WaveSpectrumParameters>);
	vWaveSpectrumParameters.def_readwrite("sig_wave_height_hm0", &WaveSpectrumParameters::sig_wave_height_hm0);
	vWaveSpectrumParameters.def_readwrite("wave_peak_direction", &WaveSpectrumParameters::wave_peak_direction);
	vWaveSpectrumParameters.def_readwrite("wave_peak_period", &WaveSpectrumParameters::wave_peak_period);
	vWaveSpectrumParameters.def_readwrite("wave_height_wind_hm0", &WaveSpectrumParameters::wave_height_wind_hm0);
	vWaveSpectrumParameters.def_readwrite("wave_height_swell_hm0", &WaveSpectrumParameters::wave_height_swell_hm0);
	vWaveSpectrumParameters.def_readwrite("wave_peak_period_wind", &WaveSpectrumParameters::wave_peak_period_wind);
	vWaveSpectrumParameters.def_readwrite("wave_peak_period_swell", &WaveSpectrumParameters::wave_peak_period_swell);
	vWaveSpectrumParameters.def_readwrite("wave_peak_direction_wind", &WaveSpectrumParameters::wave_peak_direction_wind);
	vWaveSpectrumParameters.def_readwrite("wave_peak_direction_swell", &WaveSpectrumParameters::wave_peak_direction_swell);
	vWaveSpectrumParameters.def_readwrite("wave_mean_direction", &WaveSpectrumParameters::wave_mean_direction);
	vWaveSpectrumParameters.def_readwrite("wave_mean_period_tm02", &WaveSpectrumParameters::wave_mean_period_tm02);
	vWaveSpectrumParameters.def_readwrite("wave_height_hmax", &WaveSpectrumParameters::wave_height_hmax);
	vWaveSpectrumParameters.def_readwrite("wave_height_crest", &WaveSpectrumParameters::wave_height_crest);
	vWaveSpectrumParameters.def_readwrite("wave_height_trough", &WaveSpectrumParameters::wave_height_trough);
	vWaveSpectrumParameters.def_readwrite("wave_period_tmax", &WaveSpectrumParameters::wave_period_tmax);
	vWaveSpectrumParameters.def_readwrite("wave_period_tz", &WaveSpectrumParameters::wave_period_tz);
	vWaveSpectrumParameters.def_readwrite("significant_wave_height_h1_3", &WaveSpectrumParameters::significant_wave_height_h1_3);
	vWaveSpectrumParameters.def_readwrite("mean_spreading_angle", &WaveSpectrumParameters::mean_spreading_angle);
	vWaveSpectrumParameters.def_readwrite("first_order_spread", &WaveSpectrumParameters::first_order_spread);
	vWaveSpectrumParameters.def_readwrite("long_crestedness_parameters", &WaveSpectrumParameters::long_crestedness_parameters);
	vWaveSpectrumParameters.def_readwrite("heading", &WaveSpectrumParameters::heading);
	vWaveSpectrumParameters.def_readwrite("pitch", &WaveSpectrumParameters::pitch);
	vWaveSpectrumParameters.def_readwrite("roll", &WaveSpectrumParameters::roll);
	vWaveSpectrumParameters.def_readwrite("external_heading", &WaveSpectrumParameters::external_heading);
	vWaveSpectrumParameters.def_readwrite("stdev_heading", &WaveSpectrumParameters::stdev_heading);
	vWaveSpectrumParameters.def_readwrite("stdev_pitch", &WaveSpectrumParameters::stdev_pitch);
	vWaveSpectrumParameters.def_readwrite("stdev_roll", &WaveSpectrumParameters::stdev_roll);
}