class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int num : nums) {
            if (++counts[num] > n / 2)
                return num;
        }
        return -1;
    }
};