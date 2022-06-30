#include<iostream>
using namespace std;
class node{
    public:
    int data; //the container which stores data
    node* next; //a pointer which stores address of next container
    node(int val){
        data = val;//container gets the value
        next = NULL;//next gets the adress of next container
    }
};

//How to insert to a Linked List? At the TAIL - End i.e.
void insertAtTail(node* &head,int val){//hahaha see line 14
    node* n = new node(val);//hhahaa see line 14, nothing just n with "node*" data type lmao
    if(head==NULL){
        head = n;
        return;//basically if empty linked list
    }
    node* temp=head;//a address data type to temporarily store address of the curret node
    while(temp->next!=NULL){//we accessed the 'Next' adrress bruh OOPS
        temp = temp->next;//iterating to next container
    }
    temp->next=n;//setting value if comes out of while loop
}
//How to print a linked list? - LMFAOOOO
void display(node* head){
    node* temp=head; //temp adress variable to iterate
    while(temp!=NULL){
        cout<<temp->data<<"->";//printing the value of the container at the iterating address bruh
        temp = temp->next;//temp becomes the next address OOPS bruhh
    }
    cout<<"NULL"<<endl;
}

void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    if(odd->next==NULL){
        even->next=NULL;
    }
}

int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    evenAfterOdd(head);
    display(head);

    return 0;
}