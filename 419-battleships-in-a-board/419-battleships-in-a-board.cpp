class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int counter = 0;
        unordered_set<string> cache;
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (board[row][col] == '.')
                    continue;
                if (row > 0 && board[row - 1][col] == 'X')
                    continue;
                if (col > 0 && board[row][col - 1] == 'X')
                    continue;
                counter++;
            }
        }
        return counter;
    }
};