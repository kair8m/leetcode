class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cache;
        for (char c : s)
            cache[c]++;
        for (char c : t)
        {
            if (cache[c] <= 0)
                return false;
            cache[c]--;
        }
        for (auto& entry : cache)
        {
            int count = entry.second;
            if (count > 0)
                return false;
        }
        return true;
    }
};