class Solution {
public:
    
    int binaryexp(int a,long long b,int m){
        int ans = 1;
        while(b > 0){
            if(b & 1){
                ans=(ans * 1LL * a) % m;
            }
            a=(a * 1LL * a) % m;
            b >>= 1;
        }
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        uint64_t power = b[0];
        for (int i = 1; i < b.size(); ++i)
            power = (power * 10 + b[i]) % 1140;
        return binaryexp(a, power, 1337);
    }
};