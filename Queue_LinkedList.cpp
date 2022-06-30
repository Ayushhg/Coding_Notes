#include<iostream>
using namespace std;

class node{//we define a linked list
    public:
    int data;//store the data element
    node* next;//stores the address of the next element

    node(int val){
        data=val;//whatever value we pass
        next=NULL;//iniialise with NULL
    }
};

class queue{//we define a claass queue now
    node* front;//front will be the linked list data type
    node* back;//same

    public:
    queue(){//basic constructor
        front=NULL; 
        back=NULL;
    }
    void push(int x){//push function
        node* n = new node(x);
        if(front==NULL){//if empty we will change null
            back=n;//ONLY one element na
            front=n;//head becomes n
            return;
        }
        else{
            back->next=n;
            back=n;//simply add to the last of the list
        }
    }
    void pop(){//pop function
        if(front==NULL){
            cout<<"Queue is empty!"<<endl;
            return;//underflow check
        }
        node* toDelete=front;//the first element is to be deleted
        front=front->next;//front is increamented by 1
        delete toDelete;//delete the first element
    }
    int peek(){
        if(front==NULL){
            cout<<"Empty Queue"<<endl;
            return -1;//if null then empty
        }
        return front->data;//otherwise fornt's data value
    }
    bool empty(){
        if(front==NULL){//if empty then null
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    queue q;
    q.push(5);
    q.push(4);
    q.push(8);
    q.push(3);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;


    return 0;
}