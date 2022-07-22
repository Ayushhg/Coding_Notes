#include<iostream>
using namespace std;

struct Node{

    int data;
    struct Node* right;
    struct Node* left;

    Node(int val){
        right = NULL;
        left = NULL;
        data = val;
    }

};

void preorder(Node* root){
    
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* sortedArrayToBST(int arr[],int start,int end){

    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);

    return root;
}

int main(){
    int arr[] = {10,20,30,40,50};
    Node* root = sortedArrayToBST(arr,0,4);
    preorder(root);
    return 0;
}