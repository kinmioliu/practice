class Solution {
public:
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int maxv = -100000;
            for (int j = i; j < i + k; j++) {
                maxv = max(maxv, nums[j]);
            }
            ans.push_back(maxv);
        }
        return ans;        
    }
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> maxq;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            sort(nums.begin() + i, nums.begin() + i + k);
            ans.push_back(nums[i + k - 1]);
        }
        return ans;        
    }    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int, int>> q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.empty()) {
                q.push_back(make_pair(nums[i], i));
            } else {
                if (q.size() == k || i - q.front().second >= k) {
                    q.pop_front();
                }
                while (!q.empty() && q.back().first <= nums[i]) {
                    //cout << q.back() << " ";
                    q.pop_back();
                }
                q.push_back(make_pair(nums[i], i));
            }
            if (i >= k - 1) {
                ans.push_back(q.front().first);                
            }
        }
        return ans;        
    }
};
