#include<iostream>
#include<map>

using namespace std;

int main(){

    map<int, string> m;

    m[1]="adarsh";
    m[2]="kumar";
    m[3]="singh";

    m.insert( {5,"kurmi"});
    cout<<"before earse"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<endl;
    }
    cout<<"finding value of key: "<<m.count(-5)<<endl;
    cout<<m.find(2)->second<<endl;

    m.erase(2);
    cout<<"after erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    } 

    return 0;   
} 