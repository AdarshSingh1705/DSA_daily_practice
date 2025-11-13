#include<iostream>
#include<string>
using namespace std;

bool isAlphaNumeric(char ch){
    return  (ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9');    
}

char toLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
    return (ch + ('a' - 'A'));
    }
    return ch;
}

bool isPalindrome(string s){

    int left = 0;
    int right = s.length()-1;
    while(left < right){

        while(left <= right && !isAlphaNumeric(s[left])){
            left++;
        }
        while( left <= right && !isAlphaNumeric(s[right])){
            right--;
        }

        char leftChar = toLowerCase(s[left]);
        char rightChar =  toLowerCase(s[right]);

        if(leftChar != rightChar){
            return false;
        }
        left ++;
        right--;
    }
    return true;
}

int main(){
    std::string input;
    std::cout << "Enter a phrases: ";
    std::getline(std::cin, input);

    if(isPalindrome(input)){
        std::cout << "It's a palindorme . \n";
    }else{
        std:: cout << "Not a valid Palindrome. \n";
    }

    return 0;
}