// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        for (int i = 1; i <= 2e31 - 1; ++i)
        {
            if (isBadVersion(i))
                return i;
        }
        return -1;
    }
};