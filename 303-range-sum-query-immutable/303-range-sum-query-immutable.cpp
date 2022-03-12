class NumArray {
public:
    NumArray(vector<int>& nums) : m_nums(nums) {
        
    }
    
    int sumRange(int left, int right) {
        if (left > right)
            return -1;
        if (left >= m_nums.size())
            return -1;
        int sum = m_nums[left];
        for (int i = left + 1; i <= right; ++i) {
            sum += m_nums[i];
        }
        return sum;
    }
    
private:
    vector<int> m_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */