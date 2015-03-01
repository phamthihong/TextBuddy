#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <list>
#include <cctype>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class TextBuddy{
public:
	TextBuddy();
	~TextBuddy();

	string getKeyword(string);
	string getDetail(string);
	void commandAdd(string, string);
	bool Search(string);
	void commandSearch(string);
	void commandDisplay(string);
	void commandDelete (string, string);
	void commandClear (string);
	void commandExit();
	void commandSort();
	void executionCommand(string, string);

private:
	list <string> DataList;
};

#endif
