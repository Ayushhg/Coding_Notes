#include<iostream>
using namespace std;
//Doubly linked list is nothing different...
//Only thing is it has the address of the previous node as well.
//this helps in moving both ways without issues.
class node{
    public:

    int data;
    node* next;//As usual next stores address of next node
    node* prev;//Prev store address of previous node simple

    node(int val){
        data=val;
        next=NULL;//initialize both with NULL
        prev=NULL;//same
    }
};

//To insert element at the head
void insertAtHead(node* &head, int val){

    node* n= new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
//To display elements
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
//To dellete at head
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

//To insert an element at the tail
void insertAtTail(node* &head, int val){
    if(head==NULL){//corner case if it is empty
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);//new node made
    node* temp=head;//head taken as temp to iterate

    while(temp->next!=NULL){//to the end of the doubly linked list
        temp=temp->next;//iterating to the next element
    }
    temp->next=n;//setting n as the last element
    n->prev=temp;//last element's previous will have prev address
}
//To delete an elemt from a doubly linked list!
void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,7);
    deletion(head,2);
    display(head);

    return 0;
}