class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for (int i = 0; i <= n; ++i) {
            int num = i;
            int count = 0;
            for (int shift = 0; shift < 32; ++shift) {
                if (num & 1 << shift)
                    count++;
            }
            output.push_back(count);
        }
        return output;
    }
};