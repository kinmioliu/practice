class Solution {
public:
    int countSubstrings(string s) {
        int centerPos = 0;
        int count = 0;
        for (; centerPos < s.length() - 1; centerPos++) {
            for (int i = centerPos - 1, j = centerPos + 1; i >= 0, j < s.length() - 1; i--, j++) {
                if (s[i] == s[j]) {
                    count++;
                }
                break; // the others will not be symmerty
            }
        }
        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int centerPos = 0;
        int count = 0;
        for (; centerPos < s.length(); centerPos++) {
            count++; // single character
            for (int i = centerPos - 1, j = centerPos + 1; i >= 0 && j < s.length(); i--, j++) {
                //cout << i << " " << j << endl;
                if (s[i] == s[j]) {
                    count++;
                    continue;
                }
                break; // the others will not be symmerty
            }
            for (int i = centerPos, j = centerPos + 1; i >= 0 && j < s.length(); i--, j++) {
                //cout << i << " " << j << endl;
                if (s[i] == s[j]) {
                    count++;
                    continue;
                }
                break; // the others will not be symmerty
            }
        }
        return count;
    }
};

