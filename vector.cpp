#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    //defining v
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(7);
    v.pop_back();

    //length of v
    cout<<v.size()<<endl;

    //iterator v
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it;
    }cout<<endl;

    //auto v
    for(auto element : v){
        cout<<element;
    }cout<<endl;

    //sort v
    sort(v.begin(),v.end());
    for(it=v.begin();it!=v.end();it++){
        cout<<*it;
    }cout<<endl;

    //sum of v
    int sum = accumulate(v.begin(),v.end(),0);
    cout<<sum<<endl;

    //min max of v
    int mx = *max_element(v.begin(),v.end());
    int mn = *min_element(v.begin(),v.end());
    cout<<"Min:"<<mn<<endl;
    cout<<"Max:"<<mx<<endl;

    //add to v
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);

    //fibonacci v
    partial_sum(v.begin(),v.end(),v.begin());

    for(auto element : v){
        cout<<element<<" ";
    }cout<<endl;

    //swap v
    v.swap(v2);

    return 0;
}