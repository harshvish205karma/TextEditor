#include "Editor.h"
#include<sstream>

Editor::Editor()
{
}

void Editor::insertLine(string text)
{
    undoStack.push(lines);
    
    while(!redoStack.empty()){
        redoStack.pop();
    }
    lines.push_back(text);

}

void Editor::display()
{
    for (int i = 0; i < lines.size(); i++)
    {
        cout << i + 1 << ". " << lines[i] << endl;
    }
}
void Editor::deleteLine(int lineNumber){
   if(lineNumber<1 && lineNumber>lines.size()){
    cout<<"Invalid Line Number "<<endl;
    return;
   }
   undoStack.push(lines);
   lines.erase(lines.begin()+lineNumber-1);
    while(!redoStack.empty()){
        redoStack.pop();
    }
}
void Editor::editLine(int lineNumber,string newText){
   if(lineNumber<1 && lineNumber>lines.size()){
    cout<<"Invalid Line Number "<<endl;
    return;
   }
   undoStack.push(lines);
   lines[lineNumber-1]=newText;
    while(!redoStack.empty()){
        redoStack.pop();
    }
}
vector<string>& Editor::getLines(){
    return lines;
}
void Editor::setLines(const vector<string>&newLines){
    lines = newLines;
}
void Editor::searchWord(string word){
    bool found = false;
    for(int i=0;i<lines.size();i++){
        if(lines[i].find(word)!=string::npos){
            cout<<"word found at line "<<i+1<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"word not find "<<endl;
    }
}
void Editor::replaceWord(string oldWord,string newWord){
    bool found = false;
    for(int i=0;i<lines.size();i++){
        if(lines[i].find(oldWord)!=string::npos){
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"Word not find "<<endl;
        return;
    }
    // only save if word actually found
    undoStack.push(lines);
    for(int left=0;left<lines.size();left++){
        size_t position = lines[left].find(oldWord);
        while(position!=string::npos){
            lines[left].replace(position,oldWord.length(),newWord);
            position = lines[left].find(oldWord,position+newWord.length());
        }
    }
    while(!redoStack.empty()){
        redoStack.pop();
    }
    cout<<"Word replace successfully "<<endl;
}
void Editor::showStatistics(){
    int totalLines = lines.size();
    int totalChar = 0;
    int totalWords =0;
    for(int i=0;i<lines.size();i++){
        totalChar += lines[i].length();
        stringstream ss(lines[i]);
        string word;
        while(ss>>word){
            totalWords++;
        }
    }
    cout<<"total Lines "<<totalLines<<endl;
    cout<<"total Words "<<totalWords<<endl;
    cout<<"total Char "<<totalChar<<endl;
}
void Editor::undo(){
    if(undoStack.empty()){
        cout<<"Nothing left to undo "<<endl;
        return;
    }
    redoStack.push(lines);
    lines =undoStack.top();
    undoStack.pop();
    cout<<"Undo sucessfully done "<<endl;
}
void Editor::redo(){
    if(redoStack.empty()){
        cout<<"Nothing Left to redo "<<endl;
        return;
    }
    undoStack.push(lines);
    lines = redoStack.top();
    redoStack.pop();
    cout<<" Redo done successfully "<<endl;
}
void Editor::insertLineAt(int lineNumber, string text){
    if(lineNumber<1 || lineNumber>lines.size()+1){
        cout<<"Invalid Line number "<<endl;
        return;
    }
    undoStack.push(lines);
    while(!redoStack.empty()){
        redoStack.pop();
    }
    lines.insert(lines.begin()+lineNumber-1,text);
    cout<<"Line Insert SuacessFully "<<endl;
}
void Editor::copyLine(int lineNumber){
    if(lineNumber<1 || lineNumber>lines.size()+1){
        cout<<"Invalid lineNumber "<<endl;
        return;
    }
    clipboard = lines[lineNumber-1];
    cout<<"Line copied SuccessFully "<<endl;
}
void Editor::pasteLine(int lineNumber){
    if(clipboard.empty()){
        cout<<"clipboard is empty "<<endl;
        return;
    }
    if(lineNumber<1 || lineNumber > lines.size()+1 ){
        cout<<"Invalid LineNumber "<<endl;
        return;
    }
    undoStack.push(lines);
    while(!redoStack.empty()){
        redoStack.pop();
    }
    lines.insert(lines.begin()+lineNumber-1,clipboard);
    cout<<"Line pasted successfully !"<<endl;
}
void Editor::cutLine(int lineNumber){
    if(lineNumber<1 || lineNumber>lines.size()){
        cout<<"Invalid line Number "<<endl;
        return;
    }
    undoStack.push(lines);
    clipboard = lines[lineNumber-1];
    lines.erase(lines.begin()+lineNumber-1);
    while(!redoStack.empty()){
        redoStack.pop();
    }
   
    cout<<"Line cut Successfully "<<endl;
}
void Editor::appendLine(int lineNumber, string text){
    if(lineNumber<1 && lineNumber>lines.size()){
        cout<<"Invalid input "<<endl;
        return;
    }
    undoStack.push(lines);
    lines[lineNumber-1]+=" "+text;
    while(!redoStack.empty()){
        redoStack.pop();
    }
    cout<<"Line append successfully "<<endl;
}