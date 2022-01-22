class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        uint64_t reverse = 0;
        int origin = x;
        while (x)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == origin;
    }
};