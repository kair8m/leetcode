class Solution {
public:
    
    string longestPalindrome(string s, int left, int right) {
        if (left > right)
            return {};
        string substr = string(s.begin() + left, s.begin() + right);
        string copy = substr;
        reverse(copy.begin(), copy.end());
        if (copy == substr)
            return substr;
        auto leftShift = longestPalindrome(s, left + 1, right);
        auto rightShift = longestPalindrome(s, left, right - 1);
        return leftShift.size() > rightShift.size() ? leftShift : rightShift;
    }
    
    string longestPalindrome(string s) {
        if (s.empty())
            return {};
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i + 1);
            int len = max(len1, len2);
            if (len > (end - start)) {
                start = i - ((len - 1) / 2);
                end = i + len / 2;
            }
        }
        return string(s.begin() + start, s.begin() + end + 1);
    }
    
    int expandFromMiddle(string s, int left, int right) {
        if (s.empty() || left > right)
            return 0;
        
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};