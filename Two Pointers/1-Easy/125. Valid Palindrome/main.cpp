#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //first instinct is 2 pointers , skip anything that isn't a char 
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j){
            //skip non letters
            while(i < j && !std::isalnum(static_cast<unsigned char>(s[j]))) j--;
            while(i < j && !std::isalnum(static_cast<unsigned char>(s[i]))) i++;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};


int main(){
    Solution sol; 
    string s = "A man, a plan, a canal: Panama";
    if(sol.isPalindrome(s)){
        std::printf("Palindrome\n");
    }
    else{
        std::printf("Not Palindrome\n");
    }
    return 0;
}