#include <iostream>
#include <vector>


class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) {
        for(int i = 0; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if (nums[i] == nums[j] && i != j) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    if(s.containsDuplicate({1,2,3,4})){
        std::printf("Duplicate\n");
    }
    else{
        std::printf("No Duplicate\n");
    }
}