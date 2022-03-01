class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        memset(storage, 0, static_cast<int>(10e5) + 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (storage[nums[i]] > 0)
                return nums[i];
            storage[nums[i]] = 1;
        }
        return -1;
    }
    
private:
    int storage[static_cast<int>(10e5) + 1] = {0};
};