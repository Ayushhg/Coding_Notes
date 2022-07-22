//This is a sliding window problem
#include<iostream>
using namespace std;

int smallestSubarrayWithSum(int arr[],int n,int x){
    int sum = 0;
    int minLength = n+1;
    int start = 0,end = 0;
    while(end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }

        while(sum > x && start<n){
            if(end-start < minLength){
                minLength = end-start;
            }
            sum-=arr[start++];
        }
    }
    return minLength;
}

int main(){

    int arr[] = {1,4,45,6,10,19};
    cout<<smallestSubarrayWithSum(arr,6,51);

    return 0;
}