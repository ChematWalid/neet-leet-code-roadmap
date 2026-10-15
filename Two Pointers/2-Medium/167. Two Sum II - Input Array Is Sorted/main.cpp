#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //My first intuition since the expected space complexity is O(1) and the vector is ordered
    //i should use a binary search type of 2 pointers technique
    // target = 11
    //[1,3,5,6,8,9]
    //start at 1 and 9 : 1 + 9 = 10 < 11 so go to right by 1
    // 3 and 9 : 3 + 9 = 12 > 11 : go left by 1
    // 3 and 8 : 3 + 8 = 11 , found
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0 , j = numbers.size()-1;
        while(i < j){
            if(numbers[i] + numbers[j] < target){
                i++;
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
            }
            else{
                return {i+1 ,j+1};
            }
        }
        return {0,0};
    }
};

int main(){
    return 0;
}