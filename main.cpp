#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Util{
public:
    void displaySeparator(){
        cout<<"\n"<<"___________________________________"<<"\n";
    }
};

//--------SINGLE LINKED LIST---------

struct llElement{
    int data;
    llElement* nextElement;
};

class LL{

private:
    llElement* head;
    llElement* tail;
    int size;

public:

    LL(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    llElement* createElement(int data){
        llElement* ele = new llElement;
        ele -> data = data;
        ele -> nextElement = NULL;
        return ele;
    }

    void displayElement(llElement* ele){
        cout<<"Data of the llElement "<<ele ->data<<"\n";
    }

    void addFirstEle(int val){

        llElement* temp = createElement(val);

        head = temp;
        tail = temp;

        size ++;
    }

    void addEle(int val){

        llElement* temp = createElement(val);

        tail -> nextElement = temp;
        tail = temp;

        size++;
    }

    void jumpToElement(int pos){

        llElement* browser = head;
        for (int i = 0; i < pos-1; i++) {
            browser = browser -> nextElement;
        }
        displayElement(browser);
    }

    llElement* getElement(int pos){

        llElement* browser = head;
        for (int i = 0; i < pos-1; i++) {
            browser = browser -> nextElement;
        }
        return browser;
    }

    void insertAfter(int pos, int data){
//        [A]->[C]
//        [A]->[B]->[C]
        llElement* A = getElement(pos);
        llElement* B = createElement(data);
        llElement* C = A -> nextElement;

        A -> nextElement = NULL;
        A -> nextElement = B;
        B -> nextElement = C;

        size++;

    }

    void insertAtLast(int data){
//        [A]
//        [A]->[B]

        llElement* A = getElement(size);
        llElement* B = createElement(data);
        A -> nextElement = B;
        tail = B;
        size++;
    }

    void search(int data){
        llElement* hunter = head;
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
        llElement* pointer = head;
        while (count < size){
            displayElement(pointer);
            pointer = pointer->nextElement;
            count++;
        }
    }

    void populateList(LL &ll, int count){
        ll.addFirstEle(0);
        for (int i = 1; i < count; i++) {
            ll.addEle(i);
        }
    }

};

void llDemo(){
    LL ll;
    Util util;
    ll.populateList(ll,10);
    ll.displayList();
    util.displaySeparator();
    ll.jumpToElement(100);
    ll.search(99);
    ll.insertAfter(4, -10);
    ll.insertAtLast(999);
    ll.displayList();
}

//--------DOUBLE LINKED LIST---------

struct dllElement{
    int data;
    dllElement* leftEle;
    dllElement* rightEle;
};

class DLL{
private:
    int size;
    dllElement* head;
    dllElement* tail;
public:

    DLL(){
        size = 0;
        head = NULL;
        tail = NULL;
    }

    dllElement* createEle(int data){
        dllElement* newEle = new dllElement;
        newEle -> data = data;
        newEle -> leftEle = NULL;
        newEle -> rightEle = NULL;
        return newEle;
    }

    void displayElement(dllElement* ele){
        cout<<"Data of DLL_Element = "<<ele -> data<<"\n";
    }

    void forwardTraverse(){
        int count = 0;
        dllElement* pointer = head;
        while (count < size){
            displayElement(pointer);
            pointer = pointer->rightEle;
            count++;
        }
    }

    dllElement* jumpTo(int limit){
        dllElement* pointer = head;
        for (int i = 1; i <= limit; i++) {
            pointer = pointer->rightEle;
        }
        return pointer;
    }
    void reverseTraverse(){
        int count = size;
        dllElement* pointer = tail;
        while (count>0){
            displayElement(pointer);
            pointer = pointer->leftEle;
            count--;
        }
    }

    void addElement(int data){

        /**
         * [temp]
         * [head,temp]
         * [tail,temp,head]
         * [head,tail]  [temp]
         * [head,tail] -> [temp]
         * [head,tail] <-> [temp]
         * [head] <-> [tail,temp]
         * [head] <-> [tail]    [temp]
         * [head] <-> [tail] -> [temp]
         * [head] <-> [tail]  <-> [temp]
         * [head] <-> [?] <-> [tail,temp]
         * [head] <-> [?] <-> [tail]
         *
         */

        if(head == NULL && tail == NULL){

            dllElement* temp = createEle(data);
            head = temp;
            tail = temp;
            size++;

        } else{
            dllElement* temp = createEle(data);
//            setup link from A to B
            tail -> rightEle = temp;
//            setup link from B to A
            temp -> leftEle = tail;
//            move tail
            tail = temp;
            size++;
        }
    }

    void insertAfter(int pos,int data) {
        dllElement *temp = createEle(data);
        dllElement *current = jumpTo(pos);

        //[head,current]-[?]-[?]-[?]-[tail]
        //[head]-[?]-[current]-[?]-[tail]

        dllElement* nextcurrent = NULL;
        nextcurrent = current -> rightEle;
        temp -> leftEle = current;
        temp -> rightEle = current -> rightEle;
        current -> rightEle = temp;
        nextcurrent -> leftEle = temp;
        size++;
    }

    void insertBeginning(int data){
        dllElement* temp = createEle(data);
        dllElement* nexthead ;
        nexthead = head;
        head = temp;
        temp -> rightEle = nexthead;
        nexthead -> leftEle = temp;
        size++;
    }

    void populateList(DLL &dll, int count){
        for (int i = 0; i < count; i++) {
            dll.addElement(i);
        }
    }

};

int main () {

    DLL dll;
    Util util;
    dll.populateList(dll,10);
    dll.forwardTraverse();
    util.displaySeparator();
    dll.insertAfter(4,999);
    dll.forwardTraverse();
    util.displaySeparator();
    dll.insertBeginning(11111);
    dll.forwardTraverse();
    return 0;
}