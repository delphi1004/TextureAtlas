////////////////////////////////////////////////////////////////////////////////////
//
// This is cross platform reading files class in specific directory , by John Lee
//
////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "dirent.h"
#include <vector>
#include <iostream>



using namespace std;


class JLFileManager
{

public:
	JLFileManager();
	~JLFileManager();

	int getFiles(const char *dirName, vector<string> &imageFiles);


};

