#include<iostream>
#include<queue>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        N=0;
    }

    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1=q2;
        q2=temp;

    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};

int main(){

    Stack st;
    st.push(6);
    st.push(5);
    st.push(4);
    st.push(2);
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.size()<<endl;
    return 0;
}