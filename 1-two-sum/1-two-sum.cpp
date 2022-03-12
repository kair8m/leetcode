class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); ++i)
            cache.emplace(nums[i], i);
        for (int i = 0; i < nums.size(); ++i) {
            int result = target - nums[i];
            auto entry = cache.find(result);
            if (entry == cache.end())
                continue;
            if (entry->second == i)
                continue;
            return {i, entry->second};
        }
        return {};
    }
};