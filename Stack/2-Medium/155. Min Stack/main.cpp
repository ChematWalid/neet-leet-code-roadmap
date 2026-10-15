#include <iostream>
#include <vector>
#include <stack>
#include <optional>

using namespace std;



//first instinct is to use a vector and store pairs , the top , and the minimum that is under it 
//{{0,0},{1,0},{-1,-1} ,{6,-1}}
// The minimum here is -1 , but if we pop twice , -1 is gone from the stack so the minimum is 0
class MinStack {
private:
    stack<pair<int,int>> stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val = val;
        if (!stack.empty()) {
            min_val = min(val, stack.top().second);
        }
        stack.push({val, min_val});
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */