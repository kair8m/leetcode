class Solution {
public:
    
    string replaceDigits(string s) {
        string output;
        for (int i = 0; i < s.size(); i++)
        {
            int num = atoi(string(1, s[i]).c_str());
            if (isdigit(s[i]))
                output += output.back() + num;
            else
                output += s[i];

        }
        return output;
    }
};