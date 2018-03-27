
message (STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message (STATUS "OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}")

## Include directory (header file,.....)
include_directories (
    ${libPySeek_SOURCE_DIR}/src
    ${OpenCV_INCLUDE_DIRS}
    /usr/include/libusb-1.0
)



## Link libraries
link_libraries (
    thSeekThermalPro_static
    #-lboost_program_options
    ${OpenCV_LIBRARIES}
    -lusb-1.0
)

## Target compile file
add_executable (seek_test_pro seek_test_pro.cpp)

#install (TARGETS
#    seek_test
#    seek_test_pro
#    seek_viewer
#    seek_create_flat_field
#    DESTINATION "bin"
#)
