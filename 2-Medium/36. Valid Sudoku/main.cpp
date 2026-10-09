#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<char> set;
        //check lines
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    if(set.contains(board[i][j])) return false;
                    set.insert(board[i][j]);
                }
            }
            set.clear();
        }
        set.clear();
        //check columns
        for(int j = 0 ; j < n; j++){
            for(int i = 0; i < n; i++){
                if(board[i][j] != '.'){
                    if(set.contains(board[i][j])) return false;
                    set.insert(board[i][j]);
                }
            }
            set.clear();
        }
        set.clear();
        //check squares
        for(int squareCol = 0 ; squareCol < 3 ; squareCol++){
            for(int squareRow = 0 ; squareRow < 3 ; squareRow++){
                for(int i = squareCol * 3 ; i < (squareCol + 1) * 3 ; i++){
                    for(int j = squareRow * 3 ; j < (squareRow + 1) * 3 ; j++){
                        if(board[i][j] != '.'){
                            if(set.contains(board[i][j])) return false;
                            set.insert(board[i][j]);
                        }
                    }
                }
                set.clear();
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