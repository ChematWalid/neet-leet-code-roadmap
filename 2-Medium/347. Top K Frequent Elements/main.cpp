#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "../../common/print.hpp"
#include <queue>
using namespace std;

class Solution {
public:
    
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;  
        unordered_map<int,int> freq;

        //Calculate frequency like earlier (don't need to check if it exists ,, already initialized to 0)
        for ( int num : nums )
        {
            freq[num]++;
        }
        //Push to min heap and remove the head (lowest frequency) if the size is bigger than k
        for (auto& [num, count] : freq)
        {
            minHeap.push({count, num});
            if( (int)minHeap.size() > k ) minHeap.pop();
        }
        
        vector<int> result;
        //append all of the min heap to result
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
         
        return result;
    }
};

int main(){
    Solution s ;
    vector<int> output = s.topKFrequent({1,2,1,2,1,2,3,1,3,2}, 2);
    prnt::printVector(output);
    return 0;
}