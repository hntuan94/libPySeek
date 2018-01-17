/*
 *  Test program SEEK Thermal CompactPRO
 *  Author: Maarten Vandersteegen
 */
#include <opencv2/highgui/highgui.hpp>
#include <thSeekThermalPro.h>
#include <iostream>

int main()
{
	// Instant object
	thSeekThermalPro pro;

	// Init camre
    if (!pro.seekInit()) {
        std::cout << "failed to open seek cam" << std::endl;
        return -1;
	}

	else{std::cout << "seek cam init done" << std::endl;}

	// Get frame
    while(1) {
		// Get Gray frame
		if(pro.seekRead()){
        	cv::imshow("LWIR",pro.seekGetGrayCvFrame() );
		}
		if( cv::waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    }
	
}

//int main(int argc, char** argv)
//{
//    LibSeek::SeekThermalPro seek(argc == 2 ? argv[1] : "");
//	std::cout<< "argv: "<<argv[1]<<std::endl;
//    cv::Mat frame, grey_frame;
//
//    if (!seek.open()) {
//        std::cout << "failed to open seek cam" << std::endl;
//        return -1;
//    }
//
//    while(1) {
//        if (!seek.read(frame)) {
//            std::cout << "no more LWIR img" << std::endl;
//            return -1;
//        }
//
//        cv::normalize(frame, grey_frame, 0, 65535, cv::NORM_MINMAX);
//        //cv::GaussianBlur(grey_frame, grey_frame, cv::Size(7,7), 0);
//
//        cv::imshow("LWIR", grey_frame);
//
//        char c = cv::waitKey(10);
//        if (c == 's') {
//            cv::waitKey(0);
//        }
//    }
//}
