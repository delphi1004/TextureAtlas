////////////////////////////////////////////////////////////////////////////////////
//
// This is cross platform reading files class in specific directory , by John Lee
//
////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "JLFileManager.h"
#include <string.h>

JLFileManager::JLFileManager()
{
	
}


JLFileManager::~JLFileManager()
{
	
}

int JLFileManager::getFiles(const char *dirName, vector<string> &imageFiles)
{
	struct dirent **files;
	struct dirent *ent;
	string fullPath;
	int fileCount;

	cout << endl << "searching image file(s)... in " << dirName << endl;

	fileCount = scandir(dirName, &files, NULL, alphasort);

	if (fileCount >= 0) 
	{
		for (int i = 0; i < fileCount; i++) 
		{
			ent = files[i];

			if (ent->d_type == DT_REG){

				if (strstr(ent->d_name, ".png") != NULL || strstr(ent->d_name, ".JPG") != NULL || 
					strstr(ent->d_name, ".jpg") != NULL || strstr(ent->d_name, ".JPEG") != NULL || 
					strstr(ent->d_name, ".jpeg") != NULL) 
				{
					fullPath = dirName;
					fullPath.append("/");
					fullPath.append(ent->d_name);

					imageFiles.push_back(fullPath);
				}
			}

			free(files[i]);
		}

		free(files);
	}
	else 
	{
	    fprintf(stderr, "Cannot open %s (%s)\n", dirName, strerror(errno));

		exit(EXIT_FAILURE);
	}

	cout << endl << "found " << imageFiles.size() << " image file(s)." << endl;

	return imageFiles.size();
}
