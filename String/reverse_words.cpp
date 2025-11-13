#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reversewords(std::string s){
    std::istringstream str(s); // create a stream to read words
    std::string word;
    std::vector<std::string> words;
    
    while(str >> word){
        words.push_back(word);
    }
    reverse(words.begin(), words.end());

    std::string result;
    for(size_t i = 0; i< words.size(); ++i){
        result +=words[i];
        if(i < words.size()-1){
            result +=" ";
        }
    }
    return result;
}

int main(){
    std::string s = "the sky is blue due to you";
    std::string c = reversewords(s);
    std::cout<< c <<std::endl;

    return 0;
}