class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroEntries;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[row].size(); ++col) {
                if (matrix[row][col] == 0)
                    zeroEntries.push_back(make_pair(row, col));
            }
        }
        for (const auto& entry : zeroEntries)
            expandZeroes(matrix, entry.first, entry.second);
    }
    
    void expandZeroes(vector<vector<int>>& matrix, int x, int y) {
        // expand horizontaly
        for (int col = 0; col < matrix[x].size(); ++col)
            matrix[x][col] = 0;
        // expand vertically
        for (int row = 0; row < matrix.size(); ++row) 
            matrix[row][y] = 0;
    }
};