#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    char inverse(char c){
        switch (c){
            case '{' :
                return '}';
            case '[' :
                return ']';
            case '(' :
                return ')';
            case '}' :
                return '{';
            case ']' :
                return '[';
            case ')' :
                return '(';
        }
        return ' ';
    }
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s){
            if(c == '{' || c == '[' || c == '(') stack.push(c);
            else if(stack.empty() || stack.top() != inverse(c)) return false;
            else if(stack.top() == inverse(c)) stack.pop();
        }
        return stack.empty();
    }
};

int main(){
    string s = "([])";
    Solution sol;
    printf("%d", sol.isValid(s));
}