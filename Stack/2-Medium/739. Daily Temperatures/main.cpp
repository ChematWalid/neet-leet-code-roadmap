#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack;
        vector<int> answer(temperatures.size());
        for(int i =0 ; i < temperatures.size() ; i++){
            while(!stack.empty() && temperatures[i] > stack.top().first){
                //if the temperature that we are on is bigger than the top of the stack
                //means that we found the first element that is bigger than the one in the top of the stack
                // so we modify the answer[index] (the one on top of stack) 
                auto [tem, index] = stack.top();
                stack.pop();
                answer[index] = i - index;
            }
            //push the current temperature and its index onto the stack 
            //its answer is still unknown so we keep it until a warmer temperature is found
            //we can modify it directly 
            stack.push({temperatures[i] , i});
        }
        return answer;
    }
};

int main(){
    return 0;
}