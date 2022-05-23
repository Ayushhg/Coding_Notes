#include<iostream>
#include<queue>
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

void preorder(struct Node* root){//This function prints the binary tree in preorder way
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}//1 2 4 5 3 6 7

void inorder(struct Node* root){//inorder method
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}//4 2 5 1 6 3 7

void postorder(struct Node* root){//post order method

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

int search(int inorder[],int start,int end,int curr){//to search if an element exists in a binary tree or not
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

void inorderPrint(Node* root){//inorder function same nothing different
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

Node* buildTree(int preorder[],int inorder[],int start, int end){
    static int idx = 0;//this is a function to build a tree using preorder and inorder sequences
    if(start>end){//base case
        return NULL;
    }
    int curr = preorder[idx];
    idx++;//an index to run preorder
    Node* node = new Node(curr);
    if(start==end){
        return node;//end case
    }
    int pos = search(inorder,start,end,curr);
    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,end);
    //first building left tree then, right tree.
    return node;
}

Node* buildTree2(int postorder[],int inorder[],int start,int end){
    static int ind=4;
    if(start>end){//this function build tree from postorder and inorder sequences.
        return NULL;
    }
    int val=postorder[ind];
    ind--;//variable to iterate postorder
    Node* curr=new Node(val);
    if(start==end){
        return curr;
    }

    int pos=search(inorder,start,end,val);
    curr->right = buildTree2(postorder,inorder,pos+1,end);
    curr->left = buildTree2(postorder,inorder,start,pos-1);
    //first building right tree then left tree.
    return curr;
}
//P.S. we can never make a tree out of just pre order and post order sequences
//we will always need inorder sequence.
//a tree can be made using post and pre but it must be a complete tree
//skewed trees can not be formed by just post and pre sequences. 


//Level-order traversal (coolest traversal)
void printLevelOrder(Node* root){
    if(root == NULL){//base case
        return;
    }
    queue<Node*> q;//first in first out method
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!= NULL){//if there is a null we go to a new level
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

//sum of kth level in a binary tree
int sumAtK(Node* root,int k){//exactly same approach as the level order traversal we just maintain a sum variable.
    if(root==NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum = 0;

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}


//function to count the number of nodes in a program
int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

//function to calculate the sum of all the nodes in a tree
int SumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return SumNodes(root->right)+SumNodes(root->left)+ root->data;
}

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
    cout<<"POSTORDER:";
    postorder(root);
    cout<<endl;
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int postorder[] = {4,2,5,3,1};
    Node* froot = buildTree(preorder,inorder,0,4);
    inorderPrint(froot);
    cout<<endl;

    Node* frroot = buildTree2(postorder,inorder,0,4);
    inorderPrint(frroot);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
    cout<<sumAtK(root,2)<<endl;
    cout<<countNodes(root)<<endl;
    cout<<SumNodes(root)<<endl;

    return 0;
}