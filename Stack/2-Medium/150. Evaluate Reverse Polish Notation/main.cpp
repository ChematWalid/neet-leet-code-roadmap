#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isOp(string s){
        return (s == "*" || s == "/" || s == "+" || s == "-");
    }
    int evaluate(int x , int y , string op){
        if(op == "*") return x*y;
        else if(op == "/") return x/y;
        else if(op == "+") return x+y;
        else if(op == "-") return x-y;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(string token : tokens){
            if(!isOp(token)) stack.push(stoi(token));
            else{
                int x = stack.top();
                stack.pop();
                int y = stack.top();
                stack.pop();
                int result = evaluate(y,x,token);
                stack.push(result);
            }
        }
        return stack.top();
    }
};

int main(){
    Solution s;
    vector<string> input = {"2","1","+","3","*"};
    printf("%d\n", s.evalRPN(input));
}