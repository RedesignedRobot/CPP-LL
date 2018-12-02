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

    element* createElement(int data){
        element* ele = new element;
        ele -> data = data;
        ele -> nextElement = NULL;
        return ele;
    }

    void displayElement(element* ele){
        cout<<"Data of the element "<<ele ->data<<"\n";
    }

    void addFirstEle(int val){

        element* temp = createElement(val);

        head = temp;
        tail = temp;

        size ++;
    }

    void addEle(int val){

        element* temp = createElement(val);

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

    element* getElement(int pos){

        element* browser = head;
        for (int i = 0; i < pos-1; i++) {
            browser = browser -> nextElement;
        }
        return browser;
    }

    void insertAfter(int pos, int data){
//        [A]->[C]
//        [A]->[B]->[C]
        element* A = getElement(pos);
        element* B = createElement(data);
        element* C = A -> nextElement;

        A -> nextElement = NULL;
        A -> nextElement = B;
        B -> nextElement = C;

        size++;

    }

    void insertAtLast(int data){
//        [A]
//        [A]->[B]

        element* A = getElement(size);
        element* B = createElement(data);
        A -> nextElement = B;
        tail = B;
        size++;
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

    void displaySeparator(){
        cout<<"\n"<<"___________________________________"<<"\n";
    }

    void populateList(LL &ll, int count){
        ll.addFirstEle(0);
        for (int i = 1; i < count; i++) {
            ll.addEle(i);
        }
    }

};

int main () {
    LL ll;
    ll.populateList(ll,10);
    ll.displayList();
    ll.displaySeparator();
//    ll.jumpToElement(100);
//    ll.search(99);
    ll.insertAfter(4, -10);
//    ll.insertAtLast(999);
    ll.displayList();
    return 0;
}