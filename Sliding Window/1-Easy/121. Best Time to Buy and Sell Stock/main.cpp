#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int left = 0 , right = 1;
        int profitMax = 0; 
        while(left < right && left < prices.size() && right < prices.size()){
            if(prices[left] < prices[right]){
                profitMax = max(profitMax , prices[right] - prices[left]);
                right++;
            }
            else{
                left++;
                if(right == left) right++;
            }
        }
        return profitMax;
    }
};

int main(){
    Solution s;
    vector<int> vec = {7,1,5,3,6,4};
    std::printf("max profit : %d\n", s.maxProfit(vec));
    return 0;
}