#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    //Explanation is in pdf file
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars; //O(n) space
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }       
        sort(cars.begin(), cars.end()); //O(nlogn) time
        vector<float> arrivalTimeStack; //O(n) space
        for(int i = cars.size() - 1 ; i >= 0 ; i--){
            //(distance - position) / speed
            float currCarArrivalTime = (float)(target - cars[i].first) / cars[i].second;
            arrivalTimeStack.push_back(currCarArrivalTime);
            if(arrivalTimeStack.size() >= 2 && arrivalTimeStack[arrivalTimeStack.size() - 1] <= arrivalTimeStack[arrivalTimeStack.size() - 2]){
                arrivalTimeStack.pop_back();
            }
        }
        return arrivalTimeStack.size();
    }
};

int main(){
    return 0;
}