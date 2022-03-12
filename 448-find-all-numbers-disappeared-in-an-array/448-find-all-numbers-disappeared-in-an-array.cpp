class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> cache;
        for (int num : nums)
            cache.emplace(num);
        vector<int> output;
        for (int i = 1; i <= nums.size(); ++i) {
            if (cache.find(i) != cache.end())
                continue;
            output.push_back(i);
        }
        return output;
    }
};