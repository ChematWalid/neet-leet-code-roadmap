#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "../../common/print.hpp"
using namespace std;

class Solution {
public:
    
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int,int> occ;
        vector<int> result;
        for(int num : nums){
            if(!occ.contains(num)){
                occ[num] = 1;
            }
            else{
                occ[num]++;
            }
        }
        vector<pair<int, int>> vec(occ.begin(), occ.end());
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        for(int i = 0 ; i < k ; i++){
            result.push_back(vec[i].first);
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