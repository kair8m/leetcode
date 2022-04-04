class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> cache;
        for (int num : nums)
        {
            if (cache.find(num) != cache.end())
                return true;
            cache.emplace(num);
        }
        return false;
    }
};