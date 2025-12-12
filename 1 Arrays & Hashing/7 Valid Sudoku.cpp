#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Use Vector of unordered_sets to track seen numbers
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        // Iterate through the 2D-vector
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char num = board[i][j];  // extract each character

                if (num == '.')  // skip empty cells
                    continue;

                /* calculate boxIndex: Each boxIndex contains 3 rows × 3 columns of cells
                   0 | 1 | 2
                   3 | 4 | 5
                   6 | 7 | 8
                */
                int boxIndex = (i / 3) * 3 + (j / 3); // mugUp

                // If num is already present in row/col/box => invalid
                if (rows[i].find(num) != rows[i].end() ||
                    cols[j].find(num) != cols[j].end() ||
                    boxes[boxIndex].find(num) != boxes[boxIndex].end())
                {
                    return false;
                }

                // If item not found insert into hash for future Lookup
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }

        return true;
    }
};

/***************************************************************************
 * Time Complexity : O(1), since sudoku board 9×9 grid is fixed                                                *
 * Space Complexity: O(1)                                                  *
 ***************************************************************************/

/* Remarks: 
   
*/

/* Question: 
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated 
    according to the following rules:

    1. Each row must contain the digits 1-9 without repetition.
    2. Each column must contain the digits 1-9 without repetition.
    3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    
    Note:
    - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    - Only the filled cells need to be validated according to the mentioned rules.
    

    Example 1:

    Input: board = 
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: true

    Example 2:
    Input: board = 
    [["8","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: false
    Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. 
    Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/