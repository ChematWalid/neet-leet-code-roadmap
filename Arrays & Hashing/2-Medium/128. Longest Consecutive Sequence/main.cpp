
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    //my first instinct is using a minheap
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
        }

        int maxSequence = 1;
        int sequence = 1;
        int previous = minHeap.top();
        minHeap.pop();

        while (!minHeap.empty()) {
            int current = minHeap.top();
            minHeap.pop();

            if (current == previous) {
                continue;
            } else if (current - previous == 1) {
                sequence++;
            } else {
                sequence = 1;
            }

            previous = current;

            if (sequence > maxSequence) {
                maxSequence = sequence;
            }
        }

        return maxSequence;
    }
};

int main() {
    Solution s;
    vector<int> vec = {1, 0, 1, 2};

    cout << s.longestConsecutive(vec) << '\n'; // 3
    return 0;
}
