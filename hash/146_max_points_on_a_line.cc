class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> hash;
            int dx0Cnt = 0;
            for (int j = i + 1; j < points.size(); j++) {
                double dx = points[j][0] - points[i][0];
                if (dx == 0) {
                    dx0Cnt++;
                } else {
                    double k = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    hash[k]++;
                }
            }
            int maxCnt = 0;
            for (auto node : hash) {
                maxCnt = max(maxCnt, node->second);
            }
            maxCnt = max(maxCnt, dx0Cnt);
            ans = max(maxCnt + 1, ans);
        }
        return ans;
    }
};
