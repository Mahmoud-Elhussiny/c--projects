/* fread example: read an entire file */
#include<vector>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<iomanip>
#include"flie.h"
#include"folders.h"
#include <direct.h>
#include <dirent.h>
#include<Windows.h>
using namespace std;
string order;
folders *home;
void intro()
{
	cout << "\t\t\t\t\t----->> My Memory <<-----";
	cout << "\n\n\t\t\t\t      MADE BY : MOHAMED ESAWI & MAHMOUD HUSSIEN \n\n";
}
void admin_menu()
{
	system("pause");
	system("cls");
	cout << "\n\n\n\t MAIN MENU \n";
	cout << "\t_______________________";
	cout << "\n\t*******************************";
	cout << "\n\t" << main_path;
	cout << "\n\t" << "Total size " << home->head->sizefolder/1024 /1024 << " Mg";
	cout << "\n\t" << "Free size " << (Msize - home->head->sizefolder) /1024 /1024 << " Mg";
	cout << "\n\t*******************************";
	cout << "\n\t cf : Creat Folder In Memory ";
	cout << "\n\t c2m : Copy File Into Memory ";
	cout << "\n\t p2d : paste File Into disk ";
	cout << "\n\t dir : Dir/Display ";
	cout << "\n\t delfile : Delete_File ";
	cout << "\n\t delfolder : Delete Folder";
	cout << "\n\t cd : open folder ";
	cout << "\n\t back : Back ";
	cout << "\n\t cutfolder : Cut folder ";
	cout << "\n\t copyfolder : Copy Folder ";
	cout << "\n\t pastfolder : Past Folder ";
	cout << "\n\t cutfile : Cut file ";
	cout << "\n\t copyfile : Copy File ";
	cout << "\n\t pastfile : Past File ";
	cout << "\n\t rfile : Rename_File";
	cout << "\n\t rfolder : Rename_Folder";
	cout << "\n\t m2d  : copy total memory to disc";
	cout << "\n\t l2m  : load to memory";
	cout << "\n\t 0:EXIT";
	cout << "\n Please Choice Your Option : ";
}
void choose(string in) {	
	if (in == "cf") { //Create new folder
		system("CLS");
		cout << "\t\t\t\t\t----->> Creat Folder In Memory <<-----\n";
		home->creat_folder();
	}
	else if (in == "c2m") { //Copy File from disc to memory
		system("CLS");
		cout << "\t\t\t\t\t----->> Copy File Into Memory <<-----\n";
		home->copy_D_M();
	}
	else if (in == "p2d"){//paste Into disc
		system("CLS");
		cout << "\t\t\t\t\t----->> Paste File into Disc <<-----\n";
		home->copy_M_D();
	}
	else if (in == "dir") {//Display folders and files in the current folder
		system("CLS");
		cout << "\t\t\t\t\t----->> Dir/Display <<-----\n";
		home->dir();
	}
	else if (in == "delfile") {//Delete
		system("CLS");
		cout << "\t\t\t\t\t----->> Delete <<-----\n";
		home->dell_file();
	}
	else if (in == "cd") {//Enter the folder
		system("CLS");
		cout << "\t\t\t\t\t----->> CD <<-----\n";
		home->cd();
	}
	else if (in == "back") {//Back
		system("CLS");
		cout << "\t\t\t\t\t----->> Back <<-----\n";
		home->back();
	}
	else if (in == "copyfile") {//Copy
		system("CLS");
		cout << "\t\t\t\t\t----->> Copy file<<-----\n";
		home->copy();
	}
	else if (in == "pastfile") {//Past
		system("CLS");
		cout << "\t\t\t\t\t----->> Past file <<-----\n";
		home->past();
	}
	else if (in == "rfile") {//Rename File
		system("CLS");
		cout << "\t\t\t\t\t----->> Rename_file <<-----\n";
		home->rename_file();
	}
	else if (in == "rfolder") {//Rename Folder
		system("CLS");
		cout << "\t\t\t\t\t----->> Rename_folder <<-----\n";
		home->rename_folder();
	}
	else if (in=="delfolder") {
		system("CLS");
		cout << "\t\t\t\t\t----->> Delete folder <<-----\n";
		home->del_folder();
	}
	else if (in == "cutfile") {
		system("CLS");
		cout << "\t\t\t\t\t----->> Cut File <<-----\n";
		home->cutFile();
	}
	else if (in == "cutfolder") {
		system("CLS");
		cout << "\t\t\t\t\t----->> Cut folder <<-----\n";
		home->cut_folder();
	}
	else if (in == "pastfolder") {
		system("CLS");
		cout << "\t\t\t\t\t----->> past folder <<-----\n";
		home->past_folder();
	}
	else if (in == "copyfolder") {
		system("CLS");
		cout << "\t\t\t\t\t----->> copy folder <<-----\n";
		home->copy_folder();
	}
	else if (in == "l2m") {
		system("CLS");
		cout << "\t\t\t\t\t----->> Load To Memory <<-----\n";
		home->loading();
	}
	else if (in == "m2d") {
		system("CLS");
		cout << "\t\t\t\t\t----->> copt total memory <<-----\n";
		string p;
		cout << "please, Enter The path : ";
		getline(cin, p);
		p += "\\ My_memory";
		char *b = new char[p.size() + 1];
		strcpy(b, p.c_str());
		_mkdir(b);
		home->mem = home->head;
		home->copy_memory(p);
	}
	else if (in == "0") {
		
	 }
	else{
		system("CLS");
		cout << "\t\t\t---->> The Option is not exist, Please choose again <<-----\n";
	}
}
int main() {
	cout << "please enter the memory size..\n";
	cin >> Msize;
	cin.ignore();
	Msize *= 1024 * 1024;
	home = new folders();
	intro();//the introduction
	do{
		admin_menu();//the main menu
		getline(cin, order);
		choose(order);
	} while (order != "0");
	cout << "thank you" << endl;
	Sleep(2000);
	return 0 ;
}