class Solution {
public:
    
    void printVec(const vector<int>& vec) {
        for(const auto val : vec)
            cout << val << " ";
        cout << endl;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 0);
        // calculate prefix
        int prefix = 1;
        for (int i = 0; i < nums.size(); ++i) {
            output[i] = prefix;
            prefix *= nums[i];
        }
        // calculate postfix
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            output[i] *= postfix;
            postfix *= nums[i];
        }
        return output;
        
    }
    
};