#include <bits/stdc++.h>
using namespace std;

/* Approach: BackTracking/ TreeMaze

    - We try to search the word from every cell
    - From each starting cell, we do DFS + backtracking:
        - Check for boundaries and matching current character
        - Mark cell as visited
        - Recurse to 4 neighbors for the next character
        - Restore cell when backtracking
*/

class Solution {
public:

    // 2-D Vector is passed as an input
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();    // no.of rows
        int n = board[0].size(); // no.of columns

        // Try to start the word from every cell in the board
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (board[i][j] == word[0])  // If the first character matches, start DFS from here
                {
                    if (dfs(board, i, j, word, 0))  // first character always in pos 0 
                        return true;
                }
            }
        }
        // If no starting position leads to a full match, return false
        return false;
    }

    // searches the word tarting from cell (row, col)
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int pos) {
        
        // If we've matched all characters in 'word', success!
        if (pos == word.size())
            return true;

        int m = board.size();    // no.of rows
        int n = board[0].size(); // no.of columns

        // 1. Check for crossing boundaries (on -ve index and +ve index ) while exploring all 4 directions
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;

        // 2. Character mismatch OR already visited cell while exploring all 4 directions
        if (board[row][col] != word[pos])
            return false;

        // --- At this point: board[row][col] matches word[pos] ---

        // Mark this cell as visited by temporarily changing its value to #.
        char originalChar = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions recursively: up, down, left, right
        bool found = dfs(board, row - 1, col, word, pos + 1) ||  // up
                     dfs(board, row + 1, col, word, pos + 1) ||  // down
                     dfs(board, row, col - 1, word, pos + 1) ||  // left
                     dfs(board, row, col + 1, word, pos + 1);    // right

        // Restore the original character so that other paths can use this cell
        board[row][col] = originalChar;

        return found;
    }
};

/******************************************************************************
 * Time Complexity : O(m ∗ 4^n), For each cell (m * n), we can explore up to  *
                     4 directions at each step of the word                    *
 * Space Complexity: O(n), recursion overhead                                 *
 ******************************************************************************/

/* Remarks: 
    For 2D-vector,

    rows = vec.size()	-> Number of rows
    columns = vec[i].size()	-> Number of columns in row i

    Total no.of items = rows * columns 
*/

/* Question:
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
    horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Example 1:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true

    Example 2:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true

    Example 3:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false
    
*/