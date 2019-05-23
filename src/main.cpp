#include "main.h"
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "JLFileManager.h"
#include "dirent.h"

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> imageFiles;
	vector<string>::iterator it;
	JLFileManager fileNamager;

	setlocale(LC_ALL, "");

	if (argc > 1)
	{
		if (fileNamager.getFiles(argv[1], imageFiles) > 0)
		{
			for (it = imageFiles.begin(); it < imageFiles.end(); it++)
			{
				cout << *it << endl;
			}
		}
	}
	else {
		cout << "no input directory , atlasgen [directory name]" << endl;
	}

	return 0;
}