#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    //My first instinct is that both have the same character numbers so one pass to populate the 
    //map and the other to check if they all exist and delete if their occ is 0 
    //if the map is empty at the end then it's true 
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
};


int main(){

}