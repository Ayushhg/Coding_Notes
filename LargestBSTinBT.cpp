#include<iostream>
#include<climits>
using namespace std;

struct Node{

    int data;
    Node* right;
    Node* left;

    Node(int val){
        right = NULL;
        left = NULL;
        data = val;
    }

};

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){

    if(root == NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left == NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1+leftInfo.size+rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min, min(rightInfo.min,root->data));
        curr.max = max(rightInfo.max,max(leftInfo.max,root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    curr.ans = max(leftInfo.ans,rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main(){

    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout<<largestBSTinBT(root).ans<<endl;

    return 0;
}