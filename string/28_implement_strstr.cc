class Solution {
public:
    void constructLPS(string &pattern, vector<int> lps)
    {
        int i, j; // i is proper perfix pointer, j is proper suffix pointer
        i = 0;
        lps[0] = 0; // init lps[0] = 0
        for (i = 0, j = 1; j < pattern.length();) {
            if (pattern[i] == pattern[j]) {
                pattern[j] = i + 1; // length should add 1
                i++; // move i to next character, suppose proper perfix is pattern[0:i]
                j++; // move j to next character
            } else {
                if (pattern[i] != pattern[j] && i > 0) {
                    /*
                     * AABAAAABAB,
                     * i = 4, j = 9
                     * lps[4] = 2
                     * at this time, we should move i to 'AABA's lps position i = lps[3](lps[4 - 1]), why?
                     * we match AABAA with AABAB failed, but they have common prefix AABA
                     * let me figure out this by LPS's defination
                     * AABA
                     * prefix "" A AA AAB
                     * suffix "" A BA ABA AABA
                     * if we use brute force to match the longest prefix AABAA and AABAB, we will try each proper frefix from longest(AABAB) to shortest(B)
                     * 1) AABAA AABAB
                     * 2) AABA ABAB
                     * 3) AAB BAB
                     * 4) AA AB
                     * 5) A B
                     * its obvisouly that 1) 2) 3) will dismatched because lps[AABA] is A, so we can skip 1) 2) 3) and from 4), this is dynamic programming thought
                     * */
                    i = lps[i - 1];
                } else { //pattern[i] != pattern[j] && i == 0
                    lps[j] = 0;
                    j++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) 
    {
        if (needle.strlen() == 0) {
            return 0;
        }
        vector<int> lps(needle.length(), 0);
        constructLPS(needle, lps);
        int i = 0, j = 0;
        for (; i < haystack.length(); ) {
            if (haystack[i] == needle[j]) {
                j++;
                if (j == needle.length()) {
                    return i;
                }
                i++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return -1;
    }
};


class Solution {
public:
    void constructLPS(string &pattern, vector<int> &lps)
    {
        int i, j; // i is proper perfix pointer, j is proper suffix pointer
        i = 0;
        lps[0] = 0; // init lps[0] = 0
        for (i = 0, j = 1; j < pattern.length();) {
            if (pattern[i] == pattern[j]) {
                lps[j] = i + 1; // length should add 1
                i++; // move i to next character, suppose proper perfix is pattern[0:i]
                j++; // move j to next character
            } else {
                if (pattern[i] != pattern[j] && i > 0) {
                    /*
                     * AABAAAABAB,
                     * i = 4, j = 9
                     * lps[4] = 2
                     * at this time, we should move i to 'AABA's lps position i = lps[3](lps[4 - 1]), why?
                     * we match AABAA with AABAB failed, but they have common prefix AABA
                     * let me figure out this by LPS's defination
                     * AABA
                     * prefix "" A AA AAB
                     * suffix "" A BA ABA AABA
                     * if we use brute force to match the longest prefix AABAA and AABAB, we will try each proper frefix from longest(AABAB) to shortest(B)
                     * 1) AABAA AABAB
                     * 2) AABA ABAB
                     * 3) AAB BAB
                     * 4) AA AB
                     * 5) A B
                     * its obvisouly that 1) 2) 3) will dismatched because lps[AABA] is A, so we can skip 1) 2) 3) and from 4), this is dynamic programming thought
                     * */
                    i = lps[i - 1];
                } else { //pattern[i] != pattern[j] && i == 0
                    lps[j] = 0;
                    j++;
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.length() == 0) {
            return 0;
        }
        vector<int> lps(needle.length(), 0);
        constructLPS(needle, lps);
        /*
        for (auto c : lps) {
            cout << c << " ";
        }
        cout << endl;
        */
        int i = 0, j = 0;
        for (; i < haystack.length(); ) {
            if (haystack[i] == needle[j]) {
                j++;
                i++;
                if (j == needle.length()) {
                    return i - j;
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return -1;
    }
};

