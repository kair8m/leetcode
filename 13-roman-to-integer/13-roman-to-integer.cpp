class Solution {
public:
    int romanToInt(string s) {
        static const unordered_map<char, int> romanToNumMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        char prev = 0;
        result += romanToNumMap.find(s[0])->second;
        for (int i = 1; i < s.size(); ++i)
        {
            char curr = s[i];
            prev = s[i - 1];
            int diff = romanToNumMap.find(curr)->second - romanToNumMap.find(prev)->second;
            cout << "diff " << diff << endl;
            if (diff > 0 && (diff % 4 == 0 || diff % 9 == 0))
            {
                cout << "pair found " << string(1, prev) + string(1, curr) << endl;
                result -= romanToNumMap.find(prev)->second;
                result += diff;
            }
            else
            {
                result += romanToNumMap.find(curr)->second;
            }
        }
        return result;
    }
};