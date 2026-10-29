#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxcount = 0;
        int left = 0 , right = 0;
        int count[26] = {0}; //map to count occ of chars
        while(right < s.size()){
            count[s[right] - 'A']++; // count the number of the character at the right pointer
            maxcount = max(maxcount , count[s[right] - 'A']); // update the max count of characters in the current window
            if(right - left + 1 - maxcount > k){ // if the window size minus the size of the number of the most frequent character is greater than k , then we move the left pointer to the right
                // for example : AABAB and k = 2 , right - left + 1 = 5 (the size of the window) , the maxcount is 3 because that's the max number of occ of A , 5 - 3 is 2 which is equal to k so we can replace the two B's with A's to make the whole string AAAAA
                count[s[left] - 'A']--; // we left this character so decrement
                left++; //move to right
            }
            right++; // move to right

        }
        return right - left; // return the size of the window
    }
};