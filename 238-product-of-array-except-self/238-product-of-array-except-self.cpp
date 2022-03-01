class Solution {
public:
    
    void printVec(const vector<int>& vec) {
        for(const auto val : vec)
            cout << val << " ";
        cout << endl;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = nums;
        vector<int> postfix = nums;
        // calculate prefix
        for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] *= prefix[i - 1];
        }
        
        // calculate postfix
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            postfix[i] *= postfix[i + 1];
        }
        
        printVec(prefix);
        
        printVec(postfix);
        
        // calculate output
        for (int i = 0; i < nums.size(); ++i) {
            int preval = (i == 0) ? 1 : prefix[i - 1];
            int postval = (i == nums.size() - 1) ? 1 : postfix[i + 1];
            nums[i] = preval * postval;
        }
        return nums;
        
    }
    
    //1,1,1,3,8,6 -> 24,
    
};