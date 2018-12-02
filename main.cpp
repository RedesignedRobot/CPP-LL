#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct element{
    int data;
    element* nextElement;
};

class LL{

private:
    element* head;
    element* tail;
    int size;

public:

    LL(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void displayElement(element* ele){
        cout<<"Data of the element "<<ele ->data<<"\n";
    }

    void addFirstEle(int val){

        element* temp = new element;
        temp -> data = val;
        temp -> nextElement = NULL;

        head = temp;
        tail = temp;

        size ++;
    }

    void addEle(int val){

        element* temp = new element;
        temp -> data = val;
        temp -> nextElement = NULL;

        tail -> nextElement = temp;
        tail = temp;

        size++;
    }

    void jumpToElement(int pos){

        element* browser = head;
        for (int i = 0; i < pos-1; i++) {
            browser = browser -> nextElement;
        }
        displayElement(browser);
    }

    void search(int data){
        element* hunter = head;
        bool isFound = false;
        while(hunter -> nextElement != NULL){
            if(hunter -> data == data){
                isFound = true;
                break;
            } else {
                hunter = hunter -> nextElement;
            }
        }

        if(hunter -> data == data){
            isFound = true;
        }

        if(isFound){
            cout<<"Jackpot!";
        } else if(isFound == false){
            cout<<"Not Found";
        }
    }

    void displayList(){
        int count = 0;
        element* pointer = head;
        while (count < size){
            displayElement(pointer);
            pointer = pointer->nextElement;
            count++;
        }
    }

    void populateList(LL &ll){
        ll.addFirstEle(0);
        for (int i = 1; i < 100; i++) {
            ll.addEle(i);
        }
    }

};

int main () {
    LL ll;
    ll.populateList(ll);
    ll.displayList();
//    ll.jumpToElement(100);
    ll.search(99);
    return 0;
}