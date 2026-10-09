#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../../common/print.hpp"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_occ;
        //populate the map
        for(char c : s){
            if(s_occ.contains(c)){
                s_occ[c]++;
            }
            else{
                s_occ[c] = 1;
            }
        }
        for(char c : t){
            if(!s_occ.contains(c)) return false;
            s_occ[c]--;
            if(s_occ[c] == 0) s_occ.erase(c);
        }
        return s_occ.empty();
    }
    bool notGrouped(unordered_map<int, bool>& map , int index){
        return (!map.contains(index) || !map[index]);
    }
    //my first instinct is to use the "242. Valid Anagram" and do a nested loop to find all anagams
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<int, bool> posGrouped;

        for(int groupIdx = 0 ; groupIdx < strs.size() ; groupIdx++){
            vector<string> group;
            for(int i = groupIdx ; i < strs.size(); i++){
                if(isAnagram(strs[groupIdx] , strs[i]) && notGrouped(posGrouped ,i)){
                    group.push_back(strs[i]);
                    posGrouped[i] = true;
                }
            }
            if(!group.empty()){
                result.push_back(group);
            }
            group.clear();
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    prnt::printVector(s.groupAnagrams(strs));
    return 0;
}