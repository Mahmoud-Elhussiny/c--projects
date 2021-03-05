/* fread example: read an entire file */
#include<vector>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<iomanip>
using namespace std;
bool f = 0;
long long total_size = 0;
long double Msize;
#pragma once
class flie
{
public:
	FILE * pFile;
	long long lSize;
	char * buffer;
	string name;
	size_t result;
	string get_file_name(string n) {
		string s = n;
		// Remove directory if present.
		const size_t last_slash_idx = s.find_last_of("\\/");
		if (std::string::npos != last_slash_idx)
		{
			s.erase(0, last_slash_idx + 1);
		}
		name = s;
		return s;
	}
	void copy_files_to_memory(string p) {
		name = get_file_name(p);
		char *path = new char[p.size() + 1];
		strcpy(path, p.c_str());
		pFile = fopen(path, "rb");
		if (pFile == NULL) { 
			cout << "File is not exist OR the path is invalid";
			return;
		}
		// obtain file size:
		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		rewind(pFile);
		// allocate memory to contain the whole file:
		buffer = new char[lSize];
		if (buffer == NULL) { fputs("Memory error", stderr); return; }
		// copy the file into the buffer:
		result = fread(buffer, 1, lSize, pFile);
		if (result != lSize) { fputs("Reading error", stderr); return; }
	}
	void copy_file_to_disk(string p) {
		char *path = new char[p.length() + 1];
		strcpy(path, p.c_str());
		FILE * pFile1;
		pFile1 = fopen(path, "wb");
		fwrite(buffer, sizeof(char), lSize, pFile1);
		fclose(pFile1);
	}	
};