#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) {
        std::unordered_map<int, int> occ;
        for(int num : nums){
            if(occ.contains(num)){
                occ[num]++;
            }
            else{
                occ[num] = 1;
            }
        }
        for(std::pair<int, int> p : occ){
            if(p.second > 1) return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    if(s.containsDuplicate({1,2,3,4,4})){
        std::printf("Duplicate\n");
    }
    else{
        std::printf("No Duplicate\n");
    }
}