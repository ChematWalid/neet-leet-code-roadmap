#include <iostream>

#include <vector>

using namespace std;


class Solution {
public:

    string encode(const vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};
