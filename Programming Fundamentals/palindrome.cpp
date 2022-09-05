# include <iostream>
using namespace std;

int main(){

    // check plaindrome

    int n;
    cin >> n;

    char arr[n+1];
    cin >> arr;
    
    bool check = 1;

    for(int i=0; i<n; i++)
    {
        if(arr[i] != arr[n-1-i])
        {
            check = 0;
            break;
        }
    }

    if(check == true)
        cout<<"palindrome"<<endl;
    else
    {
        cout<<"not a palindrome"<<endl;
    }
    return 0;
}