class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int M = matrix.size();
        int N = matrix[0].size();
        int xPtr = 0, yPtr = 0;
        vector<int> output;
        while (output.size() < matrix.size() * matrix[0].size()) {
            int x = xPtr;
            int y = yPtr;
            while (yPtr < N)
                output.push_back(matrix[xPtr][yPtr++]);
            if (output.size() >= matrix.size() * matrix[0].size())
                break;
            yPtr--;
            xPtr++;
            while(xPtr < M)
                output.push_back(matrix[xPtr++][yPtr]);
            if (output.size() >= matrix.size() * matrix[0].size())
                break;
            xPtr--;
            yPtr--;
            while (yPtr >= y)
                output.push_back(matrix[xPtr][yPtr--]);
            if (output.size() >= matrix.size() * matrix[0].size())
                break;
            xPtr--;
            yPtr++;
            while (xPtr > x)
                output.push_back(matrix[xPtr--][yPtr]);
            if (output.size() >= matrix.size() * matrix[0].size())
                break;
            N--;
            M--;
            xPtr++;
            yPtr++;
        }
        return output;
    }
};