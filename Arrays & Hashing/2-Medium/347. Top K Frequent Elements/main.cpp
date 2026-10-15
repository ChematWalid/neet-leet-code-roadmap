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
        // A min-heap: the element with the smallest priority value
        // (frequency) is at the top and gets popped first.
        // Each pair stores {frequency, number}.
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        > minHeap;

        // Calculate the frequency of each number.
        // freq[num] defaults to 0 when num is not yet in the map.
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        // Keep only the k most frequent elements.
        // If the heap exceeds k elements, remove the one
        // with the smallest frequency.
        for (auto& [num, count] : freq)
        {
            minHeap.push({count, num});

            if ((int)minHeap.size() > k)
                minHeap.pop();
        }

        // Extract the numbers from the heap.
        // Their order is not guaranteed to be sorted by frequency.
        vector<int> result;

        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;

    }
};

int main(){
    priority_queue<int> pq;

    pq.push(3);
    pq.push(10);
    pq.push(5);


    return 0;
}