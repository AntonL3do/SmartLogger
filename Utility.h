#define _CRT_SECURE_NO_WARNINGS

#include "Registry.h"
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

class Utility{
public:
	Utility();
	~Utility();

	void keylogger();
	void addRtoDB();
	void readR();
	void readDB();
	void exportR();
	void exportDB();

private:
	string reader(Registry* M);
	void exportToFile(string filename, Registry* M);
	void importDB();

	Registry *R;
	Registry *DB;
};

