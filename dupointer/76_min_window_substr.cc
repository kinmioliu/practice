class Solution {
public:
    string minWindow(string s, string t) {
        string curSubstr, minSubstr = s;
        vector<int> needsCnt(128, 0);
        vector<bool> needsTbl(128, false);
        vector<int> statsCnt(128, 0);
        for (auto& c : t){
            needsCnt[*c]++;
            needsTbl[*c] = true;
        }
        int l = 0;
        int r = 0;
        for (; r < s.length() && l < s.length();) {
            statsCnt[s[r]]++;
            if (!match(t, needsTbl, needsCnt, statsCnt)) {
                l++;
                continue;
            } 
            // at this time match, then slide l to right, until unmatch
            do {
                statsCnt[s[l++]]--;
            } while (!match(t, needsTbl, needsCnt, statsCnt))
            curSubStr = s.substr(l - 1, r - 1 + 1);
            minSubstr = curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;
        }
        return minSubstr;
    }

    bool match(const string& t, const vector<bool>& needsTbl,const vector<int>& needsCnt, const vector<int>& statsCnt) const
    {
        for (auto& c : t) {
            if (needsCnt[*c] > statsCnt[*c]) {
                return false;
            }
        }
        true;
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        string curSubstr, minSubstr = s;
        vector<int> needsCnt(128, 0);
        vector<bool> needsTbl(128, false);
        vector<int> statsCnt(128, 0);
        for (auto& c : t){
            needsCnt[c]++;
            needsTbl[c] = true;
        }
        //cout << endl;
        int l = 0;
        int r = 0;
        for (; r < s.length() && l < s.length();) {
            bool isMatch = false;
            do {
                statsCnt[s[r++]]++;
                isMatch = match(t, needsTbl, needsCnt, statsCnt);
            } while (r < s.length() && !isMatch);
            if (!isMatch) {
                return curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;
            }
            // at this time match, then slide l to right, until unmatch
            do {
                statsCnt[s[l++]]--;
                isMatch = match(t, needsTbl, needsCnt, statsCnt);
            } while (l < s.length() && isMatch);
            curSubstr = s.substr(l - 1, r - l + 1);
            //cout << l << "," << r << ":" << curSubstr << endl;
            minSubstr = curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;                
        }
        return minSubstr;
    }

    bool match(const string& t, const vector<bool>& needsTbl,const vector<int>& needsCnt, const vector<int>& statsCnt) const
    {
        static int lastMisMatchInx = 0;
        for (int i = lastMisMatchInx; i < t.size(); i++) {
            if (needsCnt[t[i]] > statsCnt[t[i]]) {
                lastMisMatchInx = i;
                return false;
            }
        }
        for (int i = 0; i < lastMisMatchInx; i++) {
            if (needsCnt[t[i]] > statsCnt[t[i]]) {
                lastMisMatchInx = i;
                return false;
            }
        }
        lastMisMatchInx = 0;
        return true;

        for (auto& c : t) {
            if (needsCnt[c] > statsCnt[c]) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int compareCnt;
    string minWindow(string s, string t) {
        string curSubstr, minSubstr = s;
        vector<int> needsCnt(128, 0);
        vector<bool> needsTbl(128, false);
        set<char> needsSet;
        vector<int> statsCnt(128, 0);
        for (auto& c : t){
            needsCnt[c]++;
            needsSet.insert(c);
            needsTbl[c] = true;
        }
        //cout << endl;
        int l = 0;
        int r = 0;
        for (; r < s.length() && l < s.length();) {
            bool isMatch = false;
            do {
                statsCnt[s[r++]]++;
                //isMatch = match(t, needsTbl, needsCnt, statsCnt);
                isMatch = match(needsSet, needsCnt, statsCnt);
            } while (r < s.length() && !isMatch);
            if (!isMatch) {
                cout << compareCnt << endl;
                return curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;
            }
            // at this time match, then slide l to right, until unmatch
            do {
                statsCnt[s[l]]--;
                isMatch = needsCnt[s[l]] <= statsCnt[s[l]];
                l++;
                //isMatch = needsmatch(t, needsTbl, needsCnt, statsCnt);
            } while (l < s.length() && isMatch);
            curSubstr = s.substr(l - 1, r - l + 1);
            //cout << l << "," << r << ":" << curSubstr << endl;
            minSubstr = curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;                
        }
        cout << compareCnt << endl;
        return minSubstr;
    }
    
    bool match(const set<char>& needsSet,const vector<int>& needsCnt, const vector<int>& statsCnt)
    {        
        for (auto c : needsSet) {
            compareCnt++;
            if (needsCnt[c] > statsCnt[c]) {
                return false;
            }
        }
        return true;
    }    

    bool matchv1(const string& t, const vector<bool>& needsTbl,const vector<int>& needsCnt, const vector<int>& statsCnt)
    {
        for (int i = 'a'; i <= 'z'; i++) {
            compareCnt++;
            if (needsCnt[i] > statsCnt[i]) {
                return false;
            }
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            compareCnt++;
            if (needsCnt[i] > statsCnt[i]) {
                return false;
            }
        }
        return true;
        
        for (auto& c : t) {
            compareCnt++;
            if (needsCnt[c] > statsCnt[c]) {
                return false;
            }
        }
        return true;
        
        static int lastMisMatchInx = 0;
        for (int i = lastMisMatchInx; i < t.length(); i++) {
            compareCnt++;
            if (needsCnt[t[i]] > statsCnt[t[i]]) {
                lastMisMatchInx = i;                                
                return false;
            }
        }
        for (int i = 0; i < lastMisMatchInx; i++) {
            compareCnt++;
            if (needsCnt[t[i]] > statsCnt[t[i]]) {
                lastMisMatchInx = i;
                return false;
            }
        }
        lastMisMatchInx = 0;
        return true;
    }
};
class Solution {
public:
    int compareCnt;
    string minWindow(string s, string t) {
        string curSubstr, minSubstr = s;
        vector<int> needsCnt(128, 0);
        vector<bool> needsTbl(128, false);
        set<char> needsSet;
        vector<int> statsCnt(128, 0);
        for (auto& c : t){
            needsCnt[c]++;
            needsSet.insert(c);
            needsTbl[c] = true;
        }
        int l = 0;
        int r = 0;
        for (; r < s.length() && l < s.length();) {
            bool isMatch = false;
            do {
                if (!needsTbl[s[r]]){
                    r++;
                    continue;
                }
                statsCnt[s[r++]]++;
                //isMatch = match(t, needsTbl, needsCnt, statsCnt);
                isMatch = match(needsSet, needsCnt, statsCnt);                    
                
            } while (r < s.length() && !isMatch);
            if (!isMatch) {
                return curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;
            }
            // at this time match, then slide l to right, until unmatch
            do {
                if (!needsTbl[s[l]]) {
                    l++;
                    continue;
                }
                statsCnt[s[l]]--;
                isMatch = needsCnt[s[l]] <= statsCnt[s[l]];
                l++;
                //isMatch = needsmatch(t, needsTbl, needsCnt, statsCnt);
            } while (l < s.length() && isMatch);
            curSubstr = s.substr(l - 1, r - l + 1);
            minSubstr = curSubstr.length() < minSubstr.length() ? curSubstr : minSubstr;                
        }
        return minSubstr;
    }
    
    bool match(const set<char>& needsSet,const vector<int>& needsCnt, const vector<int>& statsCnt)
    {        
        for (auto c : needsSet) {
            compareCnt++;
            if (needsCnt[c] > statsCnt[c]) {
                return false;
            }
        }
        return true;
    }    

    bool matchv1(const string& t, const vector<bool>& needsTbl,const vector<int>& needsCnt, const vector<int>& statsCnt)
    {
        for (int i = 'a'; i <= 'z'; i++) {
            compareCnt++;
            if (needsCnt[i] > statsCnt[i]) {
                return false;
            }
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            compareCnt++;
            if (needsCnt[i] > statsCnt[i]) {
                return false;
            }
        }
        return true;
        
        for (auto& c : t) {
            compareCnt++;
            if (needsCnt[c] > statsCnt[c]) {
                return false;
            }
        }
        return true;
        
        static int lastMisMatchInx = 0;
        for (int i = lastMisMatchInx; i < t.length(); i++) {
            compareCnt++;
            if (needsCnt[t[i]] > statsCnt[t[i]]) {
                lastMisMatchInx = i;                                
                return false;
            }
        }
        for (int i = 0; i < lastMisMatchInx; i++) {
            compareCnt++;
            if (needsCnt[t[i]] > statsCnt[t[i]]) {
                lastMisMatchInx = i;
                return false;
            }
        }
        lastMisMatchInx = 0;
        return true;
    }
};

