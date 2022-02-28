class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> charStatistics;
        int maxCount = 0;
        char mostFrequentChar = 0;
        for (const auto c : s) {
            if (++charStatistics[c] > maxCount) {
                maxCount = charStatistics[c];
                mostFrequentChar = c;
            }
        }
        
        int oddRemaining = ceil(s.size() / 2.0);
        
        if (maxCount > oddRemaining)
            return "";
        
        
        queue<char> even, odd;
        
        for (int i = 0; i < maxCount; ++i)
            odd.push(mostFrequentChar);
        
        charStatistics.erase(mostFrequentChar);
        
        oddRemaining -= maxCount;
        
        for (const auto& entry : charStatistics) {
            for (int i = 0; i < entry.second; ++i) {
                if (oddRemaining-- > 0)
                    odd.push(entry.first);
                else
                    even.push(entry.first);
            }
        }
        
        string output{};
        
        for (int i = 1; i <= s.size(); ++i) {
            if (i % 2 == 0) {
                output += even.front();
                even.pop();
            } else {
                output += odd.front();
                odd.pop();
            }
        }

        return output;
    }
};