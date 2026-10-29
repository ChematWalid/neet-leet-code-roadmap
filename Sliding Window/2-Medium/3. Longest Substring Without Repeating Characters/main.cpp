#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    //my first intuition is (since this is a sliding window problem set) to have a starting character first
    //then keep adding the characters to the string until we find a duplicate , if we do , we increment the left side of the window until that duplicate is gone (after saving the longest length)
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_set<char> set;
        int left = 0, right = 0;

        while (left < s.length() && right < s.length()) {

            while (set.contains(s[right])) {
                set.erase(s[left]);
                left++;
            }

            while (right < s.length() && !set.contains(s[right])) {
                set.insert(s[right]);
                right++;
            }

            maxlen = max(maxlen, right - left);
        }

        return maxlen;
    }
};