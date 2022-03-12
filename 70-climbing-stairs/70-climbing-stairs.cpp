class Solution {
public:
    int climbStairs(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (cache.find(n) != cache.end())
            return cache[n];
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        cache.emplace(n, result);
        return result;
    }
    
private:
    unordered_map<int, int> cache;
};