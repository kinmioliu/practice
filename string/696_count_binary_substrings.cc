class Solution {
public:
    int countBinarySubstrings(string s) {
        int centerPos = 0;
        int count = 0;
        for (; centerPos < s.length(); centerPos++) {
            for (int i = centerPos, j = centerPos++; i >= 0 && j < s.length(); i--, j++) {
                char l = s[i], r = s[j];
                if (s[i] == l && s[j] == r && s[i] != s[j]) {
                    count++;
                    continue;
                }
                break;
            }
        }
        return count;
        
    }
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        int centerPos = 0;
        int count = 0;
        for (; centerPos < s.length() - 1; centerPos++) {
            int i = centerPos, j = centerPos + 1;
            char l = s[i], r = s[j];
            for (; i >= 0 && j < s.length(); i--, j++) {
                if (s[i] == l && s[j] == r && s[i] != s[j]) {
                    count++;
                    continue;
                }
                break;
            }
        }
        return count;
    }
};

