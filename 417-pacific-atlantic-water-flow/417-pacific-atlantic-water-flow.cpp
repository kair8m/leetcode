class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> output;
        int rows = heights.size();
        int cols = heights[0].size();
        unordered_set<string> atl, pac;
        for (int col = 0; col < cols; ++col) {
            dfs(heights, 0, col, pac, heights[0][col]);
            dfs(heights, rows - 1, col, atl, heights[rows - 1][col]);
        }
        
        for (int row = 0; row < rows; ++row) {
            dfs(heights, row, 0, pac, heights[row][0]);
            dfs(heights, row, cols - 1, atl, heights[row][cols - 1]);
        }
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                auto coordinates = to_string(row) + " " + to_string(col);
                if (pac.find(coordinates) != pac.end() && atl.find(coordinates) != atl.end())
                    output.push_back({row, col});
            }
        }
        return output;
    }
    
    void dfs(vector<vector<int>>& heights, int r, int c, unordered_set<string>& visit, int prevHeight) {
        auto coordinates = to_string(r) + " " + to_string(c);
        auto entry = visit.find(coordinates);
        if (entry != visit.end() 
            || r < 0 
            || c < 0 
            || r == heights.size() 
            || c == heights[0].size()
            || heights[r][c] < prevHeight)
            return;
        visit.emplace(coordinates);
        dfs(heights, r - 1, c, visit, heights[r][c]);
        dfs(heights, r + 1, c, visit, heights[r][c]);
        dfs(heights, r, c - 1, visit, heights[r][c]);
        dfs(heights, r, c + 1, visit, heights[r][c]);
    }
    
private:
    unordered_map<string, int> cache;
};