class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_set<string> cache;
        unordered_map<char, int> lettersInWord, lettersInBoard;
        
        for (char c : word)
            lettersInWord[c]++;
        
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                lettersInBoard[board[row][col]]++;
            }
        }
        
        for (auto& entry : lettersInWord) {
            printf("checking if board contains letter %c %d times\r\n", entry.first, entry.second);
            int count = entry.second;
            while(count--) {
                if (lettersInBoard[entry.first]-- <= 0)
                    return false;
            }
        }
        
        printf("checking if word exists...\r\n");
        
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (exist(board, word, 0, row, col))
                    return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word, int idx, int row, int col) {
        if (idx == word.size())
            return true;
        if (row >= board.size() || row < 0)
            return false;
        if (col >= board[0].size() || col < 0)
            return false;
        if (board[row][col] != word[idx])
            return false;
        char c = board[row][col];
        board[row][col] = '*';
        bool res =  
            exist(board, word, idx + 1, row + 1, col) ||
            exist(board, word, idx + 1, row - 1, col) ||
            exist(board, word, idx + 1, row, col + 1) ||
            exist(board, word, idx + 1, row, col - 1);
        board[row][col] = c;
        return res;
    }
};