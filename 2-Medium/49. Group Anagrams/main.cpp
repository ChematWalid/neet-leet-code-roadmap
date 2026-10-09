#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <array>
#include <map>
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
    
    array<int, 26> getOcc(string str){
        array<int, 26> occ{};
        for(int i = 0 ; i < str.size(); i++){
            occ[tolower(str[i]) - 'a']++;
        }
        return occ;
    }
    
    //my first instinct is to use the "242. Valid Anagram" and do a nested loop to find all anagams
    //i did it but it's O(n²k) where k is the average length of the string , but i found a better approach
    //since all anagrams share the same number of occurences ,  i can make that the key to a map and group them there
    //basically making the frequency of chars as a hash 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<array<int, 26>, vector<string>> groups;
        for(string str : strs){
            array<int, 26> key = getOcc(str);
            groups[key].push_back(str);
        }
        for(auto& [key, value] : groups){
            result.push_back(value);
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