#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> answer(nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            answer[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            answer[i] *= product;
            product *= nums[i];
        }
        return answer;
    }
};

int main(){
    return 0;
}