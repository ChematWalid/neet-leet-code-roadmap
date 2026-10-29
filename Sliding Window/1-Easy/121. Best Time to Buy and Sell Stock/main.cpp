#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int left = 0;
    }
};

int main(){
    Solution s;
    vector<int> vec = {7,1,5,3,6,4};
    std::printf("max profit : %d\n", s.maxProfit(vec));
    return 0;
}