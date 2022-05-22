#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

# define ARR_SIZE 100


int main(){
    int listData[ARR_SIZE], argData[2];
    int indexList = 0, indexArg = 0;
    string funcName = "";
    char c;
    bool flag = false; // if get the function name
    
    while((c=getchar()) != '\n'){
        if(c != ' ')
            ungetc(c, stdin);

        if(!flag && c >= '0' && c <= '9')
            cin >> listData[indexList++];
        else if(c >= 'A' && c <= 'Z'){
            cin >> funcName;
            flag = true;
        }
        else if(flag)
            cin >> argData[indexArg++];
    }

    LinkedList *list = new LinkedList(listData, indexList);

    if(funcName == "AF")
        list->addFront(argData[0]);
    else if(funcName == "AE")
        list->addEnd(argData[0]);
    else if(funcName == "AP")
        list->addAtPosition(argData[0], argData[1]);
    else if(funcName == "S")
        list->search(argData[0]);
    else if(funcName == "DF")
        list->deleteFront();
    else if(funcName == "DE")
        list->deleteEnd();
    else if(funcName == "DP")
        list->deletePosition(argData[0]);
    else if(funcName == "GI")
        list->getItem(argData[0]);

    list->printItems();
    cout << endl;
}