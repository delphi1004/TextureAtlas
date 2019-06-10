////////////////////////////////////////////////////////////////////////////////////
//
// This is cross platform texure generator class by using OPenCV , by John Lee . 08.06.2019
//
////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <iostream>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

#define MAX_COLS 10.0
#define IMAGE_SIZE 200.0
#define IMAGE_MARGINE 5

using namespace std;
using namespace cv;



class JLTextureGen
{

private:

	Mat textureImage;

public:
	JLTextureGen();
	~JLTextureGen();

	bool createTextureAtlas(vector<string> &imageFiles);
};

