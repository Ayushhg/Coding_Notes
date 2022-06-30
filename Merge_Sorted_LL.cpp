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

node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;

    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;

    }
    return dummyNode->next;
}

node* mergeRecur(node* &head1,node* &head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecur(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecur(head1,head2->next);
    }
    return result;

}

int main(){

    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head2,6);
    insertAtTail(head2,8);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    display(head1);
    display(head2);
    node* newHead=mergeRecur(head1,head2);
    display(newHead);

    return 0;
}