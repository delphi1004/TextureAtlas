////////////////////////////////////////////////////////////////////////////////////
//
// This is cross platform reading files class in specific directory , by John Lee
//
////////////////////////////////////////////////////////////////////////////////////

#include "JLFileManager.h"
#include <string.h>

JLFileManager::JLFileManager()
{
	;
}


JLFileManager::~JLFileManager()
{
	
}

int JLFileManager::getFiles(const char *dirName, vector<string> &imageFiles)
{
	struct dirent **files;
	struct dirent *ent;
	int fileCount;
	int imageFileCount;

	imageFileCount = 0;

	cout << "searching image file(s)... in " << dirName << endl;

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
					imageFiles.push_back(ent->d_name);

					imageFileCount++;
				}
			}
		}

		for (int i = 0; i < fileCount; i++){
			free(files[i]);
		}

		free(files);
	}
	else 
	{
	    fprintf(stderr, "Cannot open %s (%s)\n", dirName, strerror(errno));

		exit(EXIT_FAILURE);
	}

	cout << "found " << imageFileCount << " image files." << endl;

	return imageFileCount;
}
