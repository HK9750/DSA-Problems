// Leetcode 794. Valid Tic-Tac-Toe State

class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int oCount = 0, xCount = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                    xCount++;
                if (board[i][j] == 'O')
                    oCount++;
            }
        }

        if (oCount > xCount || xCount > oCount + 1)
            return false;

        bool Xwins = check(board, 'X');
        bool Owins = check(board, 'O');

        if (Xwins && Owins)
            return false;
        if (Xwins && xCount == oCount)
            return false;
        if (Owins && xCount > oCount)
            return false;

        return true;
    }

private:
    bool check(vector<string> &board, char player)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player &&
                board[i][2] == player)
                return true;
            if (board[0][i] == player && board[1][i] == player &&
                board[2][i] == player)
                return true;
        }

        if (board[0][0] == player && board[1][1] == player &&
            board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player &&
            board[2][0] == player)
            return true;
        return false;
    }
};

// Explanation:

// First we check the number of X's and O's on the board. If the number of O's is greater than the number of X's or the number of X's is greater than the number of O's by more than 1, then the board is invalid.
// Next we check if both X and O have won the game. If both have won, then the board is invalid.
// If X has won and the number of X's is not equal to the number of O's, then the board is invalid.
// If O has won and the number of X's is greater than or equal to the number of O's, then the board is invalid.
// If none of the above conditions are met, then the board is valid.
// The check function checks if the player has won the game by checking the rows, columns and diagonals of the board. If the player has won, then it returns true, else it returns false.