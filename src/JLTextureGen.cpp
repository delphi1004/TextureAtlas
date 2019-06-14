////////////////////////////////////////////////////////////////////////////////////
//
// This is cross platform Texture atlas generator class by using OpenCV , by John Lee . 08.06.2019
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
	textureImage = Mat(2000, 2000, CV_8UC3, Scalar(40,40,40)); // 2000 * 2000 is just for initial size and with bit darker background
}


JLTextureGen::~JLTextureGen()
{
	;
}

void JLTextureGen::createTextureAtlas(const char *outputFileName, vector<string> &imageFiles)
{
	float scale;
	vector<string>::iterator it;
	string finalImageName;
	string finalMetaFileName;
	Mat image, destRoi;
	int posX, posY, count;
	int textureWidth, textureHeight;

	count = 0;
	scale = 1;
	posX = IMAGE_MARGINE;
	posY = IMAGE_MARGINE;
	
	finalImageName = outputFileName;
	finalMetaFileName = outputFileName;
	finalImageName.append(".jpg");
	finalMetaFileName.append(".txt");

	// to decide final texture image's width and height
	if (imageFiles.size() > MAX_COLS) {
		textureWidth = ((IMAGE_SIZE + IMAGE_MARGINE) * MAX_COLS) + IMAGE_MARGINE;

		if ((imageFiles.size() % MAX_COLS) == 0) {
			textureHeight = ((IMAGE_SIZE + IMAGE_MARGINE) * (imageFiles.size() / MAX_COLS)) + IMAGE_MARGINE;
		}
		else {
			textureHeight = ((IMAGE_SIZE + IMAGE_MARGINE) * ((imageFiles.size() / MAX_COLS)+1)) + IMAGE_MARGINE;
		}
	}
	else {
		textureWidth = ((IMAGE_SIZE + IMAGE_MARGINE) * imageFiles.size()) + IMAGE_MARGINE;
		textureHeight = (IMAGE_SIZE + IMAGE_MARGINE*2);
	}
	
	// resize final output image size related to how many images are in the source directory
	resize(textureImage, textureImage, Size(textureWidth, textureHeight));

	finalImageFile.open(finalMetaFileName);

	for (it = imageFiles.begin(); it < imageFiles.end(); it++)
	{
		cout << endl << "Processing... " << *it;

		image = imread(*it);

		if (image.empty() == true) {
			cout << " Could not open or find the image";

			continue;
		}

		if (image.cols >= image.rows) {
			scale = (image.cols / IMAGE_SIZE);
		}
		else {
			scale = (image.rows / IMAGE_SIZE);
		}

		resize(image, image, Size(round(image.cols/scale), round(image.rows/ scale))); // make source image fit to 200 * 200 size
		destRoi = textureImage(Rect(posX, posY, image.cols, image.rows)); // decide the coordination in final output image file
		image.copyTo(destRoi); // copy source image to final image

		finalImageFile << *it << SEPARATOR << posX << SEPARATOR << posY << SEPARATOR << image.cols << SEPARATOR << image.rows << endl;

		count++;

		posX += (IMAGE_SIZE + IMAGE_MARGINE);

		if (count >= MAX_COLS) {

			posX = IMAGE_MARGINE;
			posY += (IMAGE_SIZE + IMAGE_MARGINE);;

			count = 0;
		}
	}

	finalImageFile.close();

	imwrite(finalImageName, textureImage);

	cout << endl << endl << finalImageName << " has been saved";
	cout << " and the size is " << textureWidth << " * " << textureHeight << endl << endl;
}
