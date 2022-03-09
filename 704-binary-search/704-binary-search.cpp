class Solution {
public:
    int search(vector<int>& nums, int target) {   
        return search(nums, 0, nums.size() - 1, target);
    }
    
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right)
            return -1;
        int pivot = (right - left) / 2 + left;
        int curr = nums[pivot];
        if (curr == target)
            return pivot;
        else if (curr > target)
            return search(nums, left, right - 1, target);
        else
            return search(nums, left + 1, right, target);
    }
};