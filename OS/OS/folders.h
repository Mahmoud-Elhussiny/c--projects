#include<vector>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include"flie.h"
#include <direct.h>
#include <dirent.h>
class node
{
public:
	string name;
	vector<flie> files;
	vector<node*> groupOfFolders;
	node *back =NULL;
	long double sizefolder=0;
};
const int Width = 15;
const char separator = ' ';
template<typename T> void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(separator) << t;
}
string main_path = "Main_Memory:";
#pragma once
class folders
{
public:
	flie copy_file;
	node* head;
	node* load;
	node* mem;
	node* crunt_load;
	int count_of_files = 0;
	node* crunt;
	node* newF=NULL;
	folders() {
		head = new node();
		load = new node();
		head->name = "mymemory";
		crunt = head;
		mem = head;
		crunt_load = load;
	}
	void cd() {
		cout << "Please enter the folder name.\n";
		string name;
		getline(cin,name);
		for (int i = 0; i < crunt->groupOfFolders.size(); i++) {
			if (name == crunt->groupOfFolders[i]->name) {
				main_path += "\\" + crunt->groupOfFolders[i]->name;
				crunt = crunt->groupOfFolders[i];
				return;
			}
		}
		cout << "\nfolder is not exist!" << endl;
	}
	void back() {
		if (crunt->back == NULL) {
			cout << "This is the first of memory (Home)" << endl;
		}
		else {
			int t = main_path.size();
			while (main_path[--t] != '\\')
			{
				main_path.pop_back();
			}
			main_path.pop_back();
			crunt = crunt->back;
		}
	}
	void copy_memory(string path) {
		for (int i = 0; i < mem->groupOfFolders.size(); i++) {
			string s = path + "\\"+ mem->groupOfFolders[i]->name;
			char *p = new char[s.size() + 1];
			strcpy(p, s.c_str());
			_mkdir(p);
			s += "\\";
			mem = mem->groupOfFolders[i];
			copy_memory(path + "\\" + mem->name);
		}
		for (int i = 0; i < mem->files.size(); i++) {
			cout << path <<"\\" << mem->files[i].name << endl;
			mem->files[i].copy_file_to_disk(path+"\\"+mem->files[i].name);
		}
		mem = mem->back;
	}
	void creat_folder() {
		cout << "Please enter the folder name.." << endl;
		string N_folder;
		getline(cin, N_folder);
		for (int i = 0; i< crunt->groupOfFolders.size(); i++) {
			if (crunt->groupOfFolders[i]->name == N_folder) {
				cout << "This name is already exist, we cant copy it";
				return;
			}
		}
		node* Newnode;
		Newnode = new node();
		Newnode->name = N_folder;
		Newnode->back = crunt;
		crunt->groupOfFolders.push_back(Newnode);
	}
	void dir() {
		cout << "\n---------------------------------------------------------------------------- \n";
		printElement("Name", Width);
		printElement("Size (Kb)", Width);
		cout << "\n----------------------------------------------------------------------------\n";
		for (int i = 0; i < crunt->groupOfFolders.size(); i++) {
			printElement(crunt->groupOfFolders[i]->name, Width);
			printElement(crunt->groupOfFolders[i]->sizefolder / 1024, Width);
			cout << endl;
		}
		for (int j = 0; j < crunt->files.size(); j++) {
			printElement(crunt->files[j].name, Width);
			printElement(crunt->files[j].lSize / 1024, Width);
			cout << endl;
		}
		total_size = head->sizefolder;
		cout << "\nThe total size of Memory is :" << total_size / 1024 << " Kb" << endl;
	}
	void dell_file() {
		cout << "please,Enter The Name of File : ";
		string name;
		getline(cin, name);
		for (int i = 0; i < crunt->files.size(); i++) {
			if (crunt->files[i].name == name) {
				crunt->sizefolder -= crunt->files[i].lSize;
				node* loop = crunt;
				while (loop->back != NULL)
				{
					loop = loop->back;
					loop->sizefolder -= crunt->files[i].lSize;
				}
				crunt->files.erase(crunt->files.begin() + i);
				return;
			}
		}
		cout << "this file is not exist" << endl;
	}
	void rename_file() {
		cout << "please,Enter The Name of File : ";
		string name;
		getline(cin, name);
		for (int i = 0; i < crunt->files.size(); i++) {
			if (crunt->files[i].name == name) {
				cout << "please,Enter The New Name of File : ";
				string name1;
				getline(cin, name1);
				crunt->files[i].name = name1;
				return;
			}
		}
		cout << "this file is not exist" << endl;
	}
	void rename_folder() {
		cout << "Please enter the folder name.\n";
		string name, Newname;
		getline(cin, name);
		bool f = 0;
		for (int i = 0; i < crunt->groupOfFolders.size(); i++) {
			if (name == crunt->groupOfFolders[i]->name) {
				cout << "please,Enter New Name of Floder : ";
				getline(cin, Newname);
				crunt->groupOfFolders[i]->name = Newname;
				return;
			}
		}
		cout << "\nfolder is not exist!" << endl;
	}
	bool f = 0;
	void cut_folder() {
		cout << "Enter the folder name\n";
		string name;
		getline(cin, name);
		for (int i = 0; i < crunt->groupOfFolders.size(); i++) {
			if (crunt->groupOfFolders[i]->name == name) {
				newF = crunt->groupOfFolders[i];
				crunt->sizefolder -= newF->sizefolder;
				node* loop = crunt;
				while (loop->back != NULL)
				{
					loop = loop->back;
					loop->sizefolder -= newF->sizefolder;
				}
				crunt->groupOfFolders.erase(crunt->groupOfFolders.begin() + i);
				return;
			}
		}
		cout << "The folder is not exist\n";
	}
	void copy_folder() {
		cout << "Enter the folder name\n";
		string name;
		getline(cin, name);
		for (int i = 0; i < crunt->groupOfFolders.size(); i++) {
			if (crunt->groupOfFolders[i]->name == name) {
				newF = crunt->groupOfFolders[i];
				return;
			}
		}
		cout << "The folder is not exist\n";
	}
	void past_folder() {
		if (newF==NULL) {
			cout << "\nChoose the folder at first to copy or cut it\n";
			return;
		}
		for (int i = 0; i < crunt->groupOfFolders.size(); i++) {
			if (crunt->groupOfFolders[i]->name == newF->name) {
				cout << "This name is already exist, we cant copy or cut it\n";
				return;
			}
		}
		if (head->sizefolder + newF->sizefolder > Msize) {
			cout << "\nmemory will excess limit..\n";
			return;
		}
		crunt->groupOfFolders.push_back(newF);
		newF->back = crunt;
		crunt->sizefolder += newF->sizefolder;
		node* loop = crunt;
		while (loop->back != NULL)
		{
			loop = loop->back;
			loop->sizefolder += newF->sizefolder;
		}
	}
	void cutFile() {
		cout << "Enter the file name\n";
		string name1;
		getline(cin, name1);
		for (int i = 0; i < crunt->files.size(); i++) {
			if (crunt->files[i].name == name1) {
				copy_file = crunt->files[i];
				crunt->sizefolder -= crunt->files[i].lSize;
				node* loop = crunt;
				while (loop->back != NULL)
				{
					loop = loop->back;
					loop->sizefolder -= copy_file.lSize;
				}
				crunt->files.erase(crunt->files.begin() + i);
				f = 1;
				return;
			}
		}
		cout << "The file is not exist\n";
	}
	void copy() {
		cout << "Please enter the name of file in the memory.\n";
		string name;
		getline(cin, name);
		for (int i = 0; i < crunt->files.size(); i++) {
			if (crunt->files[i].name == name) {
				copy_file = crunt->files[i];
				f = 1;
				return;
			}
		}
		cout << "\nFile is not exist\n";
	}
	void past() {
		if (!f) {
			cout << "\nChoose the file at first to copy or cut it\n";
			return;
		}
		for (int i = 0; i < crunt->files.size(); i++) {
			if (crunt->files[i].name == copy_file.name) {
				cout << "This name is already exist, we cant paste it\n";
				return;
			}
		}
			if (head->sizefolder + copy_file.lSize > Msize) {
				cout << "\nmemory will excess limit..\n";
				return;
			}
			crunt->files.push_back(copy_file);
			crunt->sizefolder += copy_file.lSize;
			node* loop = crunt;
			while (loop->back != NULL)
			{
				loop = loop->back;
				loop->sizefolder += copy_file.lSize;
			}
		
	}
	void copy_M_D() {
		if (!f) {
			cout << "\nChoose the file at first to copy or cut it\n";
			return;
		}
		string  path;
		cout << "Please enter the path.\n";
		getline(cin, path);
		bool q = 0;
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == '.')
				q = 1;
		}
		if (!q) {
			path += copy_file.name;
		}
		copy_file.copy_file_to_disk(path);
	}
	void copy_D_M() {
		cout << "Please enter the path of file in the disc.\n";
		string s_path;
		getline(cin, s_path);
		flie file;
		file.copy_files_to_memory(s_path);
		if (head->sizefolder + file.lSize > Msize) {
			cout << "Memory is full" << endl;
			f = 1;
			return;
		}
		if (file.lSize == 0)
			return;
		for (int i = 0; i<crunt->files.size(); i++) {
			if (crunt->files[i].name == file.name) {
				cout << "This name is already exist, we cant copy it\n";
				return;
			}
		}
		crunt->files.push_back(file);
		crunt->sizefolder += file.lSize;
		node* loop = crunt;
		while (loop->back != NULL)
		{
			loop = loop->back;
			loop->sizefolder += file.lSize;
		}
	}
	void del_folder()
	{
		cout << "Enter the folder name\n";
		string name;
		getline(cin, name);
		for (int i = 0; i< crunt->groupOfFolders.size() ; i++){
			if (crunt->groupOfFolders[i]->name == name)
			{
				crunt->sizefolder -= crunt->groupOfFolders[i]->sizefolder;
				node* loop = crunt;
				while (loop->back != NULL)
				{
					loop = loop->back;
					loop->sizefolder -= crunt->groupOfFolders[i]->sizefolder;
				}
				crunt->groupOfFolders.erase(crunt->groupOfFolders.begin() + i);
				return;
			}
		}
		cout << "The folder is not exist\n";
	}
	bool ff;
string get_name(char* path) {
	string s(path),name="";
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != '\\')
			name += s[i];
		else
			break;
	}
	reverse(name.begin(), name.end());
	return name;
}
	void load_memory(char *basePath)
	{
		if (!ff) {
			ff = 1;
			load->name=get_name(basePath);
		}
		char path[1000];
		char s[1000];
		struct dirent *dp;
		DIR *dir = opendir(basePath);

		// Unable to open directory stream
		if (!dir)
			return;
		
		while ((dp = readdir(dir)) != NULL)
		{
			if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
			{
				
				if (dp->d_type == 16384) {
					node* Newnode;
					Newnode = new node();
					Newnode->name = dp->d_name;
					Newnode->back = crunt_load;
					crunt_load->groupOfFolders.push_back(Newnode);
					crunt_load = crunt_load->groupOfFolders[crunt_load->groupOfFolders.size() - 1];
				}
				else {
					flie *file = new flie();
					strcpy(s, basePath);// Construct new path from our base path
					strcat(s, "\\");
					strcat(s, dp->d_name);
					
					file->copy_files_to_memory(s);
					crunt_load->files.push_back(*file);
					crunt_load->sizefolder += file->lSize;
					node* loop = crunt_load;
					while (loop->back != NULL)
					{
						loop = loop->back;
						loop->sizefolder += file->lSize;
					}
				}
				strcpy(path, basePath);// Construct new path from our base path
				strcat(path, "\\");
				strcat(path, dp->d_name);
				load_memory(path);
			}
		}
		crunt_load = crunt_load->back;

		closedir(dir);
	}
	void loading() {
		ff = 0;
		load = new node();
		crunt_load = load;
		cout << "Please Enter Path.." << endl;
		string path;	
		getline(cin, path);
		char *p = new char[path.size() + 1];
		strcpy(p, path.c_str());
		DIR *d = opendir(p);
		if (d == NULL) {
			cout << "Not exist..\n";
			return;
		}
		load_memory(p);
		if (load->sizefolder + head->sizefolder <= Msize) {
			load->back = crunt;
			crunt->groupOfFolders.push_back(load);
			crunt->sizefolder += load->sizefolder;
			node* loop = crunt;
			while (loop->back != NULL)
			{
				loop = loop->back;
				loop->sizefolder += load->sizefolder;
			}
		}
		else {
			cout << "Cant load folder, The size is very big "<<endl;
		}
	}
};