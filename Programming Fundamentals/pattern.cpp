#include <iostream>
using namespace std;

int main(){
    int col;
    int row;
    cin>>col>>row;
    for(int i =1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1 || i==row || j==1 || j==col){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
    }
    
    
    return 0;
}