class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        int firstPos = -1, lastPos = -1;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (nums[l] != target) {
            return vector<int>{firstPos, lastPos};
        }
        firstPos = l;
        r = nums.size() - 1;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        lastPos = r;
        return vector<int>{firstPos, lastPos};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        int firstPos = -1, lastPos = -1;
        if (nums.size() == 0) {
            return vector<int>{firstPos, lastPos};
        }
        if (nums.size() == 1) {
            return nums[0] == target ? vector<int>{0, 0} : vector<int>{-1, -1};
        }
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (nums[l] != target) {
            return vector<int>{firstPos, lastPos};
        }
        firstPos = l;
        r = nums.size();
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        lastPos = l - 1;
        return vector<int>{firstPos, lastPos};
    }
};

