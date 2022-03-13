class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 3)
            return arr[1];
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            int midVal = arr[mid];
            int leftVal = arr[mid - 1];
            int rightVal = arr[mid + 1];
            if (rightVal > midVal)
                left = mid;
            else if (leftVal > midVal)
                right = mid;
            else
                return mid;
        }
        return right;
    }
};