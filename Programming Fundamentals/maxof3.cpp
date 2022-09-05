#include <iostream>
using namespace std;
int main(){

int n;
int n2;
int n3;

cin>>n>>n2>>n3;
if(n>n2) {
    if(n>n3) {
        cout<<n<<endl;
    }
    else{
        cout<<n3<<endl;
    }
}
else{
    if(n2>n3){
        cout<<n2<<endl;
    }
    else{
        cout<<n3<<endl;
    }
}

return 0;

}