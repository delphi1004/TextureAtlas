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

using namespace std;
using namespace cv;


class JLTextureGen
{

public:
	JLTextureGen();
	~JLTextureGen();

	bool createTextureAtlas(vector<string> &imageFiles);
};

