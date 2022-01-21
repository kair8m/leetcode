class Solution {
public:
    int numSquares(int n) {
        // ans can be 1,2,3,4 by Four Square theorem
        
        vector<int> sq;
        int ans = 4;
        for(int i = 1; i * i <= n; i++) // calculating all square number
        {
            sq.push_back(i*i);
            if(sq.back() * 2 == n)
                ans=min(ans, 2); // if n= x^2 + x^2;
            if(sq.back() * 3 == n)
                ans=min(ans, 3); // if n= x^2 + x^2 + x^2;
            
        }
        if(sq.back() == n)
            return 1; // if n is a perfect square
        
        int sz = sq.size();
        
        // calculating for ans=2  -> O(N)
        if(ans == 2)
            return ans;
        int i = 0,j = sz - 1;
        while(i < j)
        {
            if(sq[i] + sq[j] == n)
                return 2;
            if(sq[i] + sq[j] < n)
                i++;
            else j--;
        }
        // calculating for ans=3 -> O(N*N)
        if(ans == 3)
            return ans;
        
        for(int k = 0;k < sz; k++)
        {
            int req = n - sq[k];
            int i = 0, j = sz - 1;
            while(i < j)
            {
                if(sq[i] + sq[j] == req)
                    return 3;
                if(sq[i] + sq[j] < req)
                    i++;
                else j--;
            }
        }
        return 4; 
    }

};