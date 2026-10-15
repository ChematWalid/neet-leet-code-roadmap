#include <iostream>
#include <vector>
#include <algorithm>
#include "../../common/print.hpp"
using namespace std;

class Solution {
public:
    //first intuition is 2 pointers and moving the minimum between them
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int left = 0 , right = height.size()-1;
        while (left < right){
            int area = min(height[left], height[right]) * (right - left);
            if(area > maxA) maxA = area;
            if(height[left] < height[right]){
                left ++;
            }
            else{
                right--;
            }
        }
        return maxA;
    }
};

int main(){
    Solution s;
    vector<int> vec = {1,7,2,5,4,7,3,6};
    std::printf("%d", s.maxArea(vec));
    return 0;
}