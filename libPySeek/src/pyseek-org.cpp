#include <boost/python.hpp>
#include <thSeekThermalPro.h>

using namespace boost::python;

BOOST_PYTHON_MODULE(pyseek)
{
	class_<thSeekThermalPro>("thSeekThermalPro")
		.def("seekInit", &thSeekThermalPro::seekInit)
		.def("seekRead", &thSeekThermalPro::seekRead)
		.def("seekGetRawCvFrame", &thSeekThermalPro::seekGetRawCvFrame)
		.def("seekGetGrayCvFrame", &thSeekThermalPro::seekGetGrayCvFrame)
	;
}

