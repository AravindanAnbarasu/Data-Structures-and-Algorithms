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

 /* Question: 

*/