#include "FileManager.h"
void FileManager::saveFile(vector<string>&lines,string fileName){
    ofstream out(fileName);
    if(!out){
        cout<<"Error opening file "<<endl;
        return;
    }
    for(string line : lines){
        out<<line<<endl;
    }
    out.close();
    cout<<"File Saved Successfully "<<endl;
}
void FileManager::loadFile(vector<string>&lines,string FileName){
    ifstream in(FileName);
    if(!in){
        cout<<"Error in file Opening "<<endl;
        return;
    }
    lines.clear();
    string line;
    while(getline(in,line)){
        lines.push_back(line);
    }
    in.close();
    cout<<"File load Succesfully !"<<endl;
}