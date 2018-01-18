/*
 *  Seek thermal pro interface
 *  Author: Tuan Huynh
 */

#ifndef TH_SEEK_THERMAL_PRO_H
#define TH_SEEK_THERMAL_PRO_H

#include <opencv2/opencv.hpp>
#include "SeekCam.h"

#define THERMAL_PRO_WIDTH       320
#define THERMAL_PRO_HEIGHT      240
#define THERMAL_PRO_RAW_WIDTH   342
#define THERMAL_PRO_RAW_HEIGHT  260
#define THERMAL_PRO_RAW_SIZE    (THERMAL_PRO_RAW_WIDTH * THERMAL_PRO_RAW_HEIGHT)

//namespace LibSeek {

class thSeekThermalPro: public SeekCam
{
public:
    thSeekThermalPro();
    /*
     *  ffc_filename:
     *      Filename for additional flat field calibration and corner
     *      gradient elimination. If provided and found, the image will
     *      be subtracted from each retrieved frame. If not, no additional
     *      flat field calibration will be applied
     */
    thSeekThermalPro(std::string ffc_filename);

    virtual bool init_cam();
    virtual int frame_id();
    virtual int frame_counter();
	
	// Init camera
	bool seekInit();
	// Read frame
	int seekRead();
	// Return OpenCV frame format
	cv::Mat seekGetRawCvFrame();
	// Return Gray frame map 0 - 65535
	cv::Mat seekGetGrayCvFrame();

	cv::Mat process(const cv::Mat& in);

private:
    uint16_t m_buffer[THERMAL_PRO_RAW_SIZE];
	cv::Mat rawFrame;
	cv::Mat grayFrame;
	//const cv::Mat& rawFrameConv;
	//const cv::Mat& grayFrameConv;

};

//} /* LibSeek */

#endif /* TH_SEEK_THERMAL_PRO_H */
