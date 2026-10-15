#include <iostream>
#include <vector>
#include <algorithm>
#include "../../common/print.hpp"
using namespace std;

class Solution {
public:
    //Keep track of the max on the right and on the left of each height (2 passes)
    //then do the minimum between them and minus the current height (if it's bigger than the min between them then it's 0)
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        int ml = 0;
        for(int i = 0 ; i < height.size(); i++){
            maxLeft[i] = ml;
            if(height[i] > ml) ml = height[i];
        }
        int mr = 0;
        for(int i = height.size()-1; i >= 0 ; i--){
            maxRight[i] = mr;
            if(height[i] > mr) mr = height[i];
        }
        // water in i is = max(min(maxLeft[i] , maxRight[i]) - height[i],0)
        int trappedWater = 0;
        for(int i = 0 ; i < height.size(); i++){
            trappedWater += max(min(maxLeft[i] , maxRight[i]) - height[i],0);
        }
        return trappedWater;
    }
};

int main(){
    Solution s;
    vector<int> height = {4,2,0,3,2,5};
    std::printf("%d\n",s.trap(height));
    return 0;
}