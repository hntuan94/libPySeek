## Define header file
set (HEADERS
	## Seek
    SeekCam.h
    SeekDevice.h
    SeekLogging.h
    thSeekThermalPro.h
	## Convert
	container.h
	conversion.h
	template.h
	np_opencv_converter.hpp
)

## Define source file
set (SOURCES
	## Seek
    SeekCam.cpp
    SeekDevice.cpp
    thSeekThermalPro.cpp
	pyseek.cpp
	## Convert
	conversion.cpp
	np_opencv_converter.cpp
)

set (SRC ${SOURCES} ${HEADERS})

## Boost include: PLEASE_CHANGE_TO_YOUR_PATH
set(Boost_INCLUDE_DIR /home/rnd/boost_1_66_0)

## Numpy include: PLEASE_CHANGE_TO_YOUR_PATH
set(numpy_include /usr/local/lib/python2.7/dist-packages/numpy/core/include)

message (STATUS "SRC: ${SRC}")
message (STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
message (STATUS "CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message (STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message (STATUS "Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
message (STATUS "PYTHON_INCLUDE_DIRS: ${PYTHON_INCLUDE_DIRS}")
message (STATUS "numpy_include: ${numpy_include}")

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR} ## Work dir
    /usr/include/libusb-1.0
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIR} ## Boost dir
	${PYTHON_INCLUDE_DIRS}
    ${numpy_include}
)

## Compile to *.a: It will be linked to example
add_library (thSeekThermalPro_static STATIC ${SRC})
## Compile to *.so
add_library (thSeekThermalPro SHARED ${SRC})

## It will be used to create python binding 
add_library (pyseek SHARED ${SRC})

#target_link_libraries (thSeekThermalPro
target_link_libraries (pyseek
    ${OpenCV_LIBS}
    -lusb-1.0
	## Python lib: PLEASE_CHANGE_TO_YOUR_PATH
	/usr/lib/x86_64-linux-gnu/libpython2.7.so
    ## Python lib: PLEASE_CHANGE_TO_YOUR_PATH
	/home/rnd/boost_1_66_0/stage/lib/libboost_python.so
    ## Python lib: PLEASE_CHANGE_TO_YOUR_PATH
	/home/rnd/boost_1_66_0/stage/lib/libboost_numpy.so
)

set_target_properties(pyseek PROPERTIES SUFFIX .so)
set_target_properties(pyseek PROPERTIES PREFIX "")

## install library target and header files
#install (TARGETS
#    seek
#    DESTINATION "lib"
#)
#
#install (FILES ${HEADERS}
#    DESTINATION "include/seek"
#)
