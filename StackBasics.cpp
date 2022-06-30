#include<iostream>
using namespace std;

#define n 100//making a limit for no. of elemets
//if exceeded stack overflow

class stack{//made a class to implement stack

    int* arr;//arr where stack is implemented (make private - why user see?)
    int top;//top most element pointer basically

    public:
    stack(){//now stack function
        arr=new int[n];
        top=-1;//initialized as -1 
    }

    void push(int x){//To add an element in topmost stack layer
        if(top==n-1){//check is memory available
            cout<<"Stack Overflow"<<endl;
            return;        
        }
        top++;//increament top by 1(new element added na)
        arr[top]=x;//top most element is now x!
    }

    void pop(){

        if(top==-1){//just to check if it's empty
            cout<<"No element to pop!"<<endl;
            return;
        }
        top--;//popping the element, just reduce the pointer pointing the top

    }

    int Top(){
        if(top==-1){//just to check if it's empty
            cout<<"No element in stack!"<<endl;
            return -1;
        }
        return arr[top];//simple
    }

    bool empty(){
        return top==-1;
    }
    
};


int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;
    
    return 0;
}