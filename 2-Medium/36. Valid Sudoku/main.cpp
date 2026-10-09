#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {};
        int cols[9] = {};
        int boxes[9] = {};
        //every number is a bit 1 is the first bit ... 9 is the 9th bit , so if we & for example 000000001 
        //(meaning there is 1) and 000000011 (meaning there is 1 and 2)
        //means that the result is 000000001 which isn't 0 meaning there is duplicate
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int bit = 1 << (c - '1');
                int box = (i / 3) * 3 + j / 3;

                if ((rows[i] & bit) ||
                    (cols[j] & bit) ||
                    (boxes[box] & bit)) {
                    return false;
                }

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }

        return true;
    }
};



int main() {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::printf("%d", s.isValidSudoku(board));
    return 0;
}