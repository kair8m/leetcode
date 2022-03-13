class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        
        for (char c : s) {
            if (c == '#') {
                if (!a.empty())
                    a.pop_back();
                continue;
            }
            a += c;
        }
        
        for (char c : t) {
            if (c == '#') {
                if (!b.empty())
                    b.pop_back();
                continue;
            }
            b += c;
        }
        
        return a == b;
    }
};