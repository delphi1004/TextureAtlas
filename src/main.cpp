#include "main.h"
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include <JLFileManager.h>
#include <JLTextureGen.h>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> imageFiles;
	JLFileManager fileNamager;
	JLTextureGen textureGen;

	setlocale(LC_ALL, "");

	if (argc > 2)
	{
		if (fileNamager.getFiles(argv[2], imageFiles) > 0)
		{
			textureGen.createTextureAtlas(argv[1], imageFiles);
		}
	}
	else {
		cout << "no output image file name or directory name of the images , tagen [output file name] [directory name of the images]" << endl;
	}

	return 0;
}