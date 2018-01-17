#include <boost/python.hpp>
#include <thSeekThermalPro.h>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <opencv2/opencv.hpp>
#include <exception>
// np_opencv_converter
#include "np_opencv_converter.hpp"

using namespace boost::python;


BOOST_PYTHON_MODULE(pyseek)
{
	fs::python::init_and_export_converters();

	class_<thSeekThermalPro>("thSeekThermalPro")
		.def("seekInit", &thSeekThermalPro::seekInit)
		.def("seekRead", &thSeekThermalPro::seekRead)
		.def("seekGetRawCvFrame", &thSeekThermalPro::seekGetRawCvFrame)
		.def("seekGetGrayCvFrame", &thSeekThermalPro::seekGetGrayCvFrame)
	;
}

