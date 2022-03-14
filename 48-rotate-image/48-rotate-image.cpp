class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int diam = matrix.size();
        while (diam > 1) {
            int ptr = matrix.size() - diam;
            for (int i = 0; i + ptr < diam - 1; ++i) {
                int val1 = matrix[ptr][i + ptr];
                int val2 = matrix[i + ptr][diam - 1];
                int val3 = matrix[diam - 1][diam - 1 - i];
                int val4 = matrix[diam - 1 - i][ptr];
                matrix[ptr][i + ptr] = val4;
                matrix[diam - 1 - i][ptr] = val3;
                matrix[diam - 1][diam - 1 - i] =  val2;
                matrix[i + ptr][diam - 1] = val1;
            }
            diam--;
        }
    }
};