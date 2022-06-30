#include<iostream>
#include<stack>
using namespace std;

class queue{//we will use stack to implement queue
    stack<int> s1;//this is not a very good method as Dequeue function is very costly
    stack<int> s2;//push is O(1) time but pop is O(n)

    public:
    void push(int x){//simple push in stack 1
        s1.push(x);
    }
    int pop(){
        while(s1.empty() && s2.empty()){//simple error of empty
            cout<<"Empty Queue"<<endl;
            return -1;
        }
        if(s2.empty()){//add all elements from s1 to s2 (so stack reveres and now pop will work like a queue)
            while(!s1.empty()){
                s2.push(s1.top());//adding elements to s2
                s1.pop();//easy pop
            }
        }
        int topvalue=s2.top();//kinda like peek
        s2.pop();
        return topvalue;
    }
    bool empty(){//to check of empty!
        if(s1.empty() && s2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    queue q;
    q.push(2);
    q.push(4);
    q.push(7);
    q.push(3);
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.empty()<<endl;
    return 0;
}