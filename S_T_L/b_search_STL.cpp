#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int>  v;
    
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6-> "<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<"lower bound-> "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"upper bound-> "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a=3;
    int b=7;

    cout<<"max-> "<<max(a,b)<<endl;

    cout<<"min-> "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a-> "<<a<<endl;

    string abcd ="abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"abcd-> "<<abcd<<endl;

    rotate(v.begin(),v.begin()+3,v.end());
    cout<<"after rotate-> "<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
// sort function is based on the intro sort which is a hybrid sorting algorithm 
// derived from quick sort, insertion sort and heap sort.

}

