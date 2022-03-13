class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target || target < letters[0])
            return letters[0];
        int left = 0;
        int right = letters.size() - 1;
        while (left + 1 < right) {
            int mid = (right - left) / 2 + left;
            if (letters[mid] <= target)
                left = mid;
            else
                right = mid;
        }
        
        return letters[right];
    }
};