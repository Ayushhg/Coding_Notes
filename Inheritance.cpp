#include<iostream>
using namespace std;

class ayush{
    public:
    int baby;
    void funcayu(){
        cout<<"funcAyu"<<endl;
    }
};
class shivin:public ayush{
    public:
    int code;
    void funcshiv(){
        cout<<"funcShiv"<<endl;
    }
};

int main(){

    bong c;
    c.funcayu();

    return 0;
}