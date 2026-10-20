#include "Editor.h"
#include "FileManager.h"
int main(){
    Editor editor;
    FileManager filemanager;
    int choice;
    while(true){
        cout<<"\n======Text Editor====="<<endl;
        cout<<"1. Insert Line "<<endl;
        cout<<"2. Insert Line at "<<endl;
        cout<<"3. Delete Line "<<endl;
        cout<<"4. Edit Line "<<endl;
        cout<<"5. Append text in line "<<endl;
        cout<<"6. Display "<<endl;
        cout<<"7. Enter File name "<<endl;
        cout<<"8. Load a File "<<endl;
        cout<<"9. Search a word "<<endl;
        cout<<"10. Enter a word want to replace with "<<endl;
        cout<<"11. show Statistics "<<endl;
        cout<<"12. cut "<<endl;
        cout<<"13. copy "<<endl;
        cout<<"14. paste "<<endl;
        cout<<"15. Undo "<<endl;
        cout<<"16. Redo "<<endl;
        cout<<"17. Break "<<endl;
        
        cout<<" Enter choice "<<endl;
        cin>>choice;
        if(choice==1){
            string text;
            cout<<" Enter Text "<<endl;
            cin.ignore(); // removes new line so getline works properly
            getline(cin,text);
            editor.insertLine(text);
        }
        else if(choice==2){
            int lineNumber;
            string text;
            cout<<"Enter lineNumber "<<endl;
            cin>>lineNumber;
            cin.ignore();
            cout<<"Enter text "<<endl;
            getline(cin,text);
            editor.insertLineAt(lineNumber,text);
        }
        else if(choice==3){
         int lineNumber;
         cout<<"Enter Line Number "<<endl;
         cin>>lineNumber;
         editor.deleteLine(lineNumber);
        }
        else if(choice==4){
        int lineNumber;
        string newText;
        cout<<"Enter LineNumber "<<endl;
        cin>>lineNumber;
        cin.ignore();
        getline(cin,newText);
        editor.editLine(lineNumber,newText);
        }
        else if(choice==5){
            int lineNumber;
            string text;
            cout<<"Enter line Number "<<endl;
            cin>>lineNumber;
            cin.ignore();
            getline(cin,text);
            editor.appendLine(lineNumber,text);
        }
        else if(choice==6){
            editor.display();
        }
        else if(choice==7){
            string fileName;
            cout<<"Enter FileName : ";
            cin>>fileName;
            filemanager.saveFile(editor.getLines(),fileName);
        }
        else if(choice==8){
            string fileName;
            cout<<"enter File Name ";
            cin>>fileName;
            filemanager.loadFile(editor.getLines(),fileName);
        }
        else if(choice==9){
            string word;
            cout<<"Enter a word to search "<<endl;
            cin.ignore();
            getline(cin,word);
            editor.searchWord(word);
        }
        else if(choice==10){
            string oldWord;
            string newWord;
            cout<<"Enter word to replace : "<<endl;
            cin.ignore();
            getline(cin,oldWord);
            cout<<"Enter the newWord "<<endl;
            getline(cin,newWord);
            editor.replaceWord(oldWord,newWord);
        }
        else if(choice==11){
            editor.showStatistics();
        }
        else if(choice==12){
            int lineNumber;
            cout<<"Enter line Number to cut "<<endl;
            cin>>lineNumber;
            editor.cutLine(lineNumber);
        }
        else if(choice==13){
            int lineNumber;
            cout<<"Enter line number "<<endl;
            cin>>lineNumber;
            editor.copyLine(lineNumber);
        }
        else if(choice==14){
            int lineNumber;
            cout<<"Enter line number to paste "<<endl;
            cin>>lineNumber;
            editor.pasteLine(lineNumber);
        }
        else if(choice==15){
            editor.undo();
        }
       else if(choice==16){
            editor.redo();
        }
        else if(choice==17){
            break;
        }
        else{
            cout<<"Invalid Text "<<endl;
            break;
        }
    }
    return 0;
}
