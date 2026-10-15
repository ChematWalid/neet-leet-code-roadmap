#include <iostream>
#include <vector>
#include <algorithm>
#include "../../common/print.hpp"
using namespace std;

class Solution {
public:
    //O(n²) time and O(1) space target hmm
    // obvious solution is using 3 nested for loops
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        for(int i = 0 ; i < nums.size(); i++){
            //sskip duplicate fixed values to avoid duplicate triplets
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            //if nums[i] > 0 means that anything after it is bigger than 0 (sorted array)
            if(nums[i] > 0) break;
            int l = i + 1, r = nums.size() - 1;
            //2 Pointers
            while(l < r){
                int threesum = nums[i] + nums[r] + nums[l];
                if(threesum > 0){
                    //if it's bigger than 0 , we need a smaller number so we go left
                    r--;
                } 
                else if (threesum < 0){
                    //if it's smaller than 0 , we need a bigger number so we go right
                    l++;
                }
                else{
                    res.push_back({nums[i] , nums[r] , nums[l]});
                    //skip duplicate left/right values after finding a valid triplet
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<int> vec = {-1,0,1,2,-1,-4};
    prnt::printVector(s.threeSum(vec));
    return 0;
}