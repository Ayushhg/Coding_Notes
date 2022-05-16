#include<iostream>
using namespace std;

struct Node{//Binary tree is like a flow chart which does in two-directions
    int data;//i.e. left and right (data stores the node value)
    struct Node* left;//node left is the left of the binary tree
    struct Node* right;//mode right is the right of the binary tree

    Node(int val){//constructor to make a node
        data = val;//stores the main data value
        left = NULL;//left node intialized as NULL
        right = NULL;//right node "
    }
};

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}//1 2 4 5 3 6 7

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}//4 2 5 1 6 3 7

void postorder(struct Node* root){

    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    //4 5 2 6 7 3 1
}

// the below binary tree will look something like this
    
//        1
//       /  \
//      2    3
//     / \  /  \
//    4   5 6   7 


int main(){//let's make a simple binary tree

    struct Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    //preorder
    cout<<"PREORDER: ";
    preorder(root);
    cout<<endl;
    cout<<"INORDER: ";
    inorder(root);
    cout<<endl;
    cout<<"POSTORDER: ";
    postorder(root);
    cout<<endl;


    return 0;
}