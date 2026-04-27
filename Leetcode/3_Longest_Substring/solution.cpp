//
// Created by nick on 4/26/26.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string long_str = "";   // Hold curr longest str
        string substr = "";     // Hold curr working str


        for (char c : s) {      // Iterate through each char in string  

            if (substr.find(c) != string::npos){    // If char found in string, erase up to that char in substr
                substr = substr.erase(0, substr.find(c) + 1);
            }
            
            substr += c; // Add new character to substr

            if (substr.size() > long_str.size())    // If substr is longer than the curr long str, replace long str
            {
                long_str = substr;
            }
        }

        return long_str.size();
    }
};