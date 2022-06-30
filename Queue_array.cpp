#include<iostream>
using namespace std;
#define n 20
class queue{//queue is a line, first in first out simple
    int *arr;
    int front;//starting of a queue (oldest member)
    int back;//end of a queue (newwest member)

    public:
    queue(){//Implementation using arrays
        arr = new int[n];
        front= -1;//just to intialize
        back=-1;//same
    }

    void push(int x){//push an element to the back (queue)
        if(back==n-1){//what if queue limit is reached
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }

    void pop(){//to pop from front (queue)
        if(front==-1 || front>back){
            cout<<"No elements in Queue!"<<endl;
            return;
        }
        front++;//elements can be there wherever they want to be but we only consider numbers between front and back pointer
    }//so, we increament front and reduce the size of the queue, simple!

    int peek(){//returns the first element of the queue
        if(front==-1 || front>back){
            cout<<"No elements in Queue!"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){//returns if queue is empty or not
        if(front==-1 || front>back){
            return true;
        }
        return false;
    }
};

int main(){

    queue q;
    q.push(5);
    q.push(4);
    q.push(8);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;

    return 0;
}