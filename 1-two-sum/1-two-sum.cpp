class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); ++i) {
            auto entry = cache.find(target - nums[i]);
            if (entry != cache.end())
                return {entry->second, i};
            cache[nums[i]] = i;
        }
        return {};
    }
};