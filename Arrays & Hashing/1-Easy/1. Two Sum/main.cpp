#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //Naive approach is O(n²) time and O(1) extra space of comparing each pair if they add up to target , 
    //but the right approach is storing the nums in a map and searching for target - nums[i] if it exists
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int > pos;
        for(int i = 0 ; i < nums.size() ; i++){
            pos[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(pos.contains(target - nums[i]) && i != pos[target - nums[i]]){
                return {i, pos[target - nums[i]]};
            }
        }
        return {0,0};
    }
};

int main (){
    return 0;
}