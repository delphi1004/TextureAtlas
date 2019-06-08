////////////////////////////////////////////////////////////////////////////////////
//
// This is cross platform Texture generator class by using OpenCV , by John Lee . 08.06.2019
//
////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <JLTextureGen.h>

JLTextureGen::JLTextureGen()
{
	Mat image;

	image = imread("test.jpg");

	//imshow("My first OpenCV", image);

	//waitKey(0);
}


JLTextureGen::~JLTextureGen()
{
	
}

bool JLTextureGen::createTextureAtlas(vector<string> &imageFiles)
{
	bool result;
	vector<string>::iterator it;
	Mat image;

	result = false;

	for (it = imageFiles.begin(); it < imageFiles.end(); it++)
	{
		cout << "Loading... " << *it << endl;

		image = imread(*it);

		//imshow("My first OpenCV", image);

		//waitKey(0);
	}

	return result;
}
