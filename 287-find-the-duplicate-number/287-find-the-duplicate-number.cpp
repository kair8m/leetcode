class Solution {
public:
    // wtf ???
    int findDuplicate(vector<int>& nums) {
        int fastPtr = nums[0];
        int slowPtr = nums[0];
        // find intersection
        do {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
            fastPtr = nums[fastPtr];
        } while (slowPtr != fastPtr);
        cout << "found intersection at ptr " << fastPtr << endl;
        int slowStart = nums[0];
        int slowIntersect = slowPtr;
        while(slowStart != slowIntersect) {
            slowStart = nums[slowStart];
            slowIntersect = nums[slowIntersect];
        }
        return slowIntersect;
    }
};