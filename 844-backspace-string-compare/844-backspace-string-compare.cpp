class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sPtr = s.size() - 1;
        int tPtr = t.size() - 1;
        
        int sSkips = 0;
        int tSkips = 0;
        
        while (sPtr >= 0 || tPtr >= 0) {
            while (sPtr >= 0) {
                if (s[sPtr] == '#') {
                    sSkips++;
                    sPtr--;
                } else if (sSkips > 0) {
                    sPtr--;
                    sSkips--;
                } else {
                    break;
                }
            }
            
            while (tPtr >= 0) {
                if (t[tPtr] == '#') {
                    tSkips++;
                    tPtr--;
                } else if (tSkips > 0) {
                    tPtr--;
                    tSkips--;
                } else {
                    break;
                }
            }
            if (sPtr >= 0 && tPtr >= 0 && s[sPtr] != t[tPtr])
                return false;
            if ((sPtr >= 0) != (tPtr >= 0))
                return false;
            sPtr--;
            tPtr--;
        }
        return true;
    }
};