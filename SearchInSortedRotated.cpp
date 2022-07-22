#include<iostream>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right){
    if(left>right){
        return -1;
    }

    int mid = (left+right)/2;
    if(arr[mid]==key){
        return mid;
    }

    if(arr[left]<=arr[mid]){
        if(key>=arr[left] && key<= arr[mid]){
            return searchInRotatedArray(arr,key,left,mid-1);
        }
        return searchInRotatedArray(arr,key,mid+1,right);
    }

    if(key>=arr[mid] && key<=arr[right]){
        return searchInRotatedArray(arr,key,mid+1,right);
    }
    return searchInRotatedArray(arr,key,left,mid-1);

}

int main(){

    int arr[] = {6,7,8,9,10,1,2,5};
    cout<<searchInRotatedArray(arr,8,0,7);

    return 0;
}