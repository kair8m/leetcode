class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const auto& log : logs)
        {
            if (log == "./")
                continue;
            else if (log == "../")
                depth = max(depth - 1, 0);
            else
                depth++;
        }
        return max(depth, 0);
    }
};