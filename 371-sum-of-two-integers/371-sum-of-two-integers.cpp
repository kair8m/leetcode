class Solution {
public:
    int getSum(int a, int b) {
        int mask = a | b;
        int remainBits = a & b;
        while (remainBits)
        {
            mask = mask ^ remainBits;
            remainBits = remainBits & ~(1u << 31);
            int temp = (remainBits << 1);
            remainBits = mask & temp;
            mask = mask | (temp);
        }
        return mask;
    }
};