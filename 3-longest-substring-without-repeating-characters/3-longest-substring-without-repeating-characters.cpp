class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        // Length of the given input string
	    int n = s.size();
        // Length of longest substring
        int result = 0;
        // Map to store visited characters along with their index
        unordered_map<char, int> charIndexMap;
        // start indicates the start of current substring
        int start = 0;
        // Iterate through the string and slide the window each time you find a duplicate
        // end indicates the end of current substring
        for (int end = 0; end < n; end++) 
        {
            // Check if the current character is a duplicate
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                int duplicateIndex = charIndexMap[s[end]];
                // Update the result for the substring in the current window before we found duplicate character
                result = max(result, end - start);
                // Remove all characters before the new
                for (int i = start; i <= duplicateIndex; i++)
                {
                    charIndexMap.erase(s[i]);
                }
                // Slide the window since we have found a duplicate character
                start = duplicateIndex + 1;
            }
            // Add the current character to hashmap
            charIndexMap[s[end]] = end;
        }
        // Update the result for last window
        // For a input like "abc" the execution will not enter the above if statement for checking duplicates
        result = max(result, n - start);
        return result;
    }
};