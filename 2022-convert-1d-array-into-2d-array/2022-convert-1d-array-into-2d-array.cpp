class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> output;
        if (original.size() % n != 0)
            return {};
        if (original.size() / n != m)
            return {};
        while (!original.empty()) {
            vector<int> row;
            int rowCount = n;
            while (rowCount--) {
                row.push_back(original.back());
                original.pop_back();
            }
            reverse(row.begin(), row.end());
            output.push_back(row);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};