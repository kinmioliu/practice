class Solution {
public:
    bool isAnagram(string s, string t) {
        int bucketS[26] = {0};
        int bucketT[26] = {0};
        for (auto c : s) {
            bucketS[c - 'a']++;
        }
        for (auto c : t) {
            bucketT[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (bucketS[i] != bucketT[i]) {
                return false;
            }
        }
        return true;
    }
};
