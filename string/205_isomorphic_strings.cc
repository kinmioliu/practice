class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // badc baba
        vector<unsigned short> replaceTbl(255, 0xffff); // 0xffff is invalid ascii
        vector<bool> usedTbl(255, false); // 0xffff is invalid ascii
        for (int i = 0; i < s.length(); i++) {
            if (replaceTbl[s[i]] == 0xffff) {
                //cout << s[i] << "->" << t[i] << endl;
                if (usedTbl[t[i]]) {
                    return false;
                }
                replaceTbl[s[i]] = t[i]; // t[i] should never be used
                usedTbl[t[i]] = true;
            } else {
                //cout << s[i] << "replace" << t[i] << endl;                
                if (replaceTbl[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
