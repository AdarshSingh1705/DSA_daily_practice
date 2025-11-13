#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("Adarsh", 3);
    m.insert(p);

    // second method
    pair<string, int> pair2("Singh", 2);
    m.insert(pair2);

    // 3rd method
    m["mera"] = 1;
    m["mera"] = 2;

    //searching
    cout << m["mera"] <<" ";
    cout << m.at("Adarsh") << " ";
    cout << m["unkown"] << " ";
    cout << m.at("unkown") << " ";
    // size
    cout<< m.size() << " ";

    // to check presence, erase
    cout << m.count("singh") << " ";
    cout << m.erase("unkown") << " ";
    cout << m.size() << endl;

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it -> first <<" " << it-> second << endl;
        it++;
    }

    return 0;
}