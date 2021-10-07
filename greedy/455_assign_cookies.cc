#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(), g.end()); 
        sort(s.begin(), s.end());
        int unassignedCookieInx = 0;
        int curChildrenCookieSize = 0;
        int i = 0;
        for (; i < g.size(); i++) {
            curChildrenCookieSize = 0;
            while (g[i] > curChildrenCookieSize) {
                if (unassignedCookieInx >= s.size()) {
                    return i;
                }
                curChildrenCookieSize = s[unassignedCookieInx];
                unassignedCookieInx++;
            }
        }
        return i;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 3};
    vector<int> b{1, 1};
    int content = s.findContentChildren(a, b);
    cout << content << endl;
    return 0;
}
