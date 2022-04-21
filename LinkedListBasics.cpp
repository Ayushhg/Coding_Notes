#include<iostream>
using namespace std;
//Not difficult stuff
//basically we use class method only nothing different
//One node, one data
//we keep data in a linked chain
//previous container store address of next container
//not a contigous data structure!

//template of a linked list
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
//How to insert element before the head? - Seriously?
void insertAtHead(node* &head,int val){
    node* n = new node(val);//gotta take the address of the first element
    n->next=head;//the adrress of the element to be added becomes the head - sorry the other way round
    head=n;//n is a pointer that adds the address of the new node to the head.

}
//How to search if an element exists in the Linked List?
bool Search(node* head,int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
//How to insert in middle bruhh?
void insertAtMid(node* &head,int position, int d){
    node* temp = head;
    int cnt=1;
    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    node* nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}
//how to delete a node??
void deletion(node* &head,int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        return;
    }

    node* temp = head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* toDelete = temp->next;
    temp->next=temp->next->next;

    delete toDelete;
}
//How to delete at the head?
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
//How to reverse a singly linked list mah guy?
node* reversal(node* head){
    node* prevptr = NULL;//address of previous
    node* currptr = head;//address of current
    node* nextptr;//next
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
//Reverse using Recursion
node* recursiveReverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead= recursiveReverse(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newhead;
}
//Reverse-K Problem
node* reverseK(node* &head, int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reverseK(nextptr,k);
    }
    return prevptr;
}

int length(node* head){
    int l=0;
    node* temp=head;

    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* &head1, node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
int main(){

    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head1,7);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    insertAtTail(head2,11);
    intersect(head1,head2,4);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2)<<" ";
    

    return 0;
}