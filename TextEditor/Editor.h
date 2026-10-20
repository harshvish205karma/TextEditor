#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

class Editor
{
private:
    vector<string> lines;
    stack<vector<string>>undoStack;
    stack<vector<string>>redoStack;
    string clipboard;

public:
    Editor();

    void insertLine(string text);

    void insertLineAt(int lineNumber, string text);

    void deleteLine(int lineNumber);
     
    void editLine(int lineNumber,string newText);
    
    vector<string>&getLines();

    void setLines(const vector<string>&newLines);

    void searchWord(string word);

    void replaceWord(string oldWord,string newWord);

    void showStatistics();
    
    void undo();

    void redo();

    void copyLine(int lineNumber);

    void cutLine(int lineNumber);

    void pasteLine(int lineNumber);

    

    void appendLine(int lineNumber,string text);

    void display();
};

#endif