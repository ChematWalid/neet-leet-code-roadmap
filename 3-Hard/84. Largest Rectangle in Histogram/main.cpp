#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<pair<int,int>> posAndHeight;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!posAndHeight.empty() && posAndHeight.back().second > heights[i]){
                auto [index, height] = posAndHeight.back();
                posAndHeight.pop_back();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            posAndHeight.push_back({start, heights[i]});
        }
        for(auto [index , height] : posAndHeight){
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
        }
        return maxArea;
    }
};

int main(){
    return 0;
}