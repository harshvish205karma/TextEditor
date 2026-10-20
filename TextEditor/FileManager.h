#ifndef FILEMANAGER_H
#define FILEMANAGER_H
 
#include <iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class FileManager{
public:
void saveFile(vector<string>&lines,string fileName);
void loadFile(vector<string>&lines,string fileName);
};
#endif