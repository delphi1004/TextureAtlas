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

	if (argc > 1)
	{
		if (fileNamager.getFiles(argv[1], imageFiles) > 0)
		{
			textureGen.createTextureAtlas(imageFiles);
		}
	}
	else {
		cout << "no input directory , atlasgen [directory name]" << endl;
	}

	return 0;
}