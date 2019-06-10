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
#include <math.h>

JLTextureGen::JLTextureGen()
{
	textureImage = Mat(2000, 2000, CV_8UC3, Scalar(40,40,40)); // 2000 * 2000 is just for initial size
}


JLTextureGen::~JLTextureGen()
{
	;
}

bool JLTextureGen::createTextureAtlas(vector<string> &imageFiles)
{
	bool result;
	float scale;
	vector<string>::iterator it;
	Mat image, destRoi;
	int posX, posY, count;
	int textureWidth, textureHeight;

	count = 0;
	posX = IMAGE_MARGINE;
	posY = IMAGE_MARGINE;
	scale = 1;
	result = false;

	textureWidth = ((IMAGE_SIZE+10) * MAX_COLS);
	textureHeight = round(imageFiles.size() / 10.0) * (IMAGE_SIZE + IMAGE_MARGINE*2);

	resize(textureImage, textureImage, Size(textureWidth, textureHeight));

	for (it = imageFiles.begin(); it < imageFiles.end(); it++)
	{
		image = imread(*it);

		if (image.cols >= image.rows) {
			scale = (image.cols / IMAGE_SIZE);
		}
		else {
			scale = (image.rows / IMAGE_SIZE);
		}

		resize(image, image, Size(image.cols/scale, image.rows/ scale));

		destRoi = textureImage(Rect(posX, posY, image.cols, image.rows));

		image.copyTo(destRoi);

		cout << "Loading... " << *it << " : " << "X = " << posX << " Y = " << posY << " Width = " << image.cols << " Height = " << image.rows << endl;

		count++;

		posX += (IMAGE_SIZE + IMAGE_MARGINE);

		if (count >= MAX_COLS) {
			posX = 0;
			posY += (IMAGE_SIZE + IMAGE_MARGINE);;

			count = 0;
		}
	}

	imwrite("test.png", textureImage);

	return result;
}
