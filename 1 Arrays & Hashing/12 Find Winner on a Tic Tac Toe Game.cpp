#include <bits/stdc++.h>
using namespace std;

/* Approach: 2D Vector
*/

class Solution {
public:
string tictactoe(vector<vector<int>>& moves) {

        // Create a 3x3 board initialized with 0
        vector<vector<int>> board(3, vector<int>(3, 0));

        // Fill the 3x3 board with nx2-moves 2D Array, worst case 9x2
        // 0 = empty, 1 = A's move, 2 = B's move
        for (int i = 0; i < moves.size(); i++)
        {

            int row = moves[i][0];
            int column = moves[i][1];

            // Player A moves on even turns, B moves on odd turns
            if (i % 2 == 0)
                board[row][column] = 1;   // A plays
            else
                board[row][column] = 2;   // B plays
        }
        
        // Check winner A
        if (checkWinner(board, 1))
            return "A";

        // Check winner B
        if (checkWinner(board, 2))
            return "B";

        // If less than 9 moves → game is not finished
        if (moves.size() < 9)
            return "Pending";

        // All 9 filled but no winner → draw
        return "Draw";
    }

    // Function to check if player p has won
    bool checkWinner(vector<vector<int>>& board, int p) {

        // Check all rows and columns in the board
        for (int i = 0; i < 3; i++) {

            // Check all rows
            if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
                return true;

            // Check all columns
            if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
                return true;
        }

        // Check main diagonal
        if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
            return true;

        // Check anti diagonal
        if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
            return true;

        // No win
        return false;
    }

};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    Assume a 2D vector as a Vector , whose elements are again a Vector. As simple as that.
*/

/* Question:
    Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

    - Players take turns placing characters into empty squares ' '

    - The first player A always places 'X' characters, while the second player B always places 'O' 
    characters.
    
    - 'X' and 'O' characters are always placed into empty squares, never on filled ones.

    - The game ends when there are three of the same (non-empty) character filling any row, column, 
    or diagonal. 
    
    - The game also ends if all squares are non-empty.
    
    - No more moves can be played if the game is over. 
    
    Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the 
    ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). 
    In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

    You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is
    initially empty, and A will play first.

    Example 1:
    Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
    Output: "A"
    Explanation: A wins, they always play first

    Example 2:
    Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
    Output: "B"
    Explanation: B wins.

    Example 3:
    Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
    Output: "Draw"
    Explanation: The game ends in a draw since there are no moves to make.
*/