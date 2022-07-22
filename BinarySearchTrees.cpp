#include<iostream>
#include<climits>
#include<stack>
using namespace std;

struct Node{//Binary Search trees are very very similar to binary trees.
//its a type of binary tree which used to easily search for an element in
//in the binary tree by using a method to sort the values while builidng the tree
    int data;
    struct Node* right;
    struct Node* left;

    Node(int val){
        right = NULL;
        left = NULL;
        data = val;
    }

};
//A binary tree has all its smaller values towards the left branch
//and the bigger values towards the right branch
//A BST is very simple to make:
Node* insertBST(Node* root, int val){

    if(root==NULL){//if we reach to the last node we simply add the node here
        return new Node(val);//we create a node with the input value at the last node!
    }
    if(val<root->data){//if the val is less than the current node we will go left!
        root->left = insertBST(root->left, val);
    }
    else{//if the val is more than the current node we will go right
        root->right = insertBST(root->right, val);
    }
    return root;
}

Node* searchInBST(Node* root,int key){//This function searchs for the given key in a BST
//It is extremely optimized as it runs in O(log(N)) time complexity.

    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

Node* constructBSTfromPreorder(int preorder[],int* preorderIdx, int key, int min, int max, int n){

    if(*preorderIdx>=n){
        return NULL;
    }
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *preorderIdx = *preorderIdx+1;

        if(*preorderIdx<n){
            root->left = constructBSTfromPreorder(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);

        }
        if(*preorderIdx<n){
            root->right = constructBSTfromPreorder(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);

        }
    }

    return root;
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root,int key){//Function to delete from a binary tree

    if(key < root->data){//simple case 1 and 2 delete (i.e. if key has no nodes or a single node)
        root->left = deleteInBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right,key);
    }

    else{//multiple nodes
        if(root->left == NULL){//case 1 & 2
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){//case 1 & 2
            Node* temp = root->left;
            free(root);
            return temp;
        }//case 3 if key has two nodes!
        Node* temp = inorderSucc(root->right);//find the next inorder succesor and replace with the root
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);//simply delete the key!

    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
//simple inorder print
}//MAKE SURE THAT INORDER PRINT OF ANY BST IS SORTED!

void printPreorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

//check for BST
bool isBST(Node* root, Node* min=NULL, Node* max=NULL){

    if(root==NULL){
        return true;
    }

    if(min != NULL && root->data<=min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left,min,root);
    bool rightValid = isBST(root->right,root,max);
    return leftValid && rightValid;
}

void zigzagTraversal(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

        if(leftToRight){
            if(temp->left){
                nextLevel.push(temp->left);
            }
            if(temp->right){
                nextLevel.push(temp->right);
            }
        }
        else{
            if(temp->right){
                nextLevel.push(temp->right);
            }
            if(temp->left){
                nextLevel.push(temp->left);
            }
        }

        }
        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);

        }

    }

}

//Identical BSTs or not?
bool isIdentical(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left,root2->left);
        bool cond3 = isIdentical(root1->right,root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }
    }
}


int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    Node* root2 = NULL;
    root2 = insertBST(root2, 5);
    insertBST(root2,1);
    insertBST(root2,3);
    insertBST(root2,4);
    insertBST(root2,2);
    insertBST(root2,7);
    // if(searchInBST(root,4)==NULL){
    //     cout<< " DOES NOT EXIST"<<endl;   
    // }
    // else{
    //     cout<<"EXISTS"<<endl;
    // }

    // root = deleteInBST(root,4);

    // inorder(root);//1 2 3 4 5 7

    // int preorder[] = {10,2,1,13,11};
    // int n = 5;
    // int preorderIdx = 0;
    // Node* root = constructBSTfromPreorder(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    // printPreorder(root);

    // Node* root = new Node(5);
    // root->left = new Node(2);
    // root->right = new Node(8);
    // cout<<isBST(root,NULL,NULL)<<endl;
    zigzagTraversal(root);
    cout<<endl;
    cout<<isIdentical(root,root2);

    return 0;
}