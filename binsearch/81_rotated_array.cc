class Solution {
public:
    // nums couldn't null
    bool search(vector<int>& nums, int target) {
        // find pivot pos use bs
        int pivot = nums];
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] < nums[m - 1]) {
                pivot_pos = m;
                break;
            }
            if (nums[m] > pivot) {
                l = m + 1;
            } else if (nums[m] < pivot) {
                r = m - 1;
            }
        }
        // search target use bs
        
    }\
    bool search(vector<int>& nums, int target) {
        int l = 0; r = nums.size() - 1, m;
        int pivot = nums[r];
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] > pivot) {
                // [l,m] sorted
                if (nums[m] == target) {
                    return true;
                } else it (nums[m] > target) {
                    return binary_search(nums.begin(), nums.begin() + m, target);
                } else {
                    l = m + 1; // continue search
                }
            } else if (nums[m] < pivot) {
                if (nums[m] == target) {
                    return true;
                } else if (nums[m] < target) {
                    return binary_search(nums.begin() + m, nums.end(), target);
                } else {
                    r = m - 1;
                }
            } else {
                l = l + 1;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        int pivot = nums[r];
        while (l <= r) {
            if (nums[l] == target || nums[r] == target) {
                return true;
            }
            m = (l + r) / 2;
            if (nums[m] > pivot) {
                // [l,m] sorted
                if (nums[m] == target) {
                    return true;
                } else if (nums[m] > target && nums[l] < target) {
                    return binary_search(nums.begin(), nums.begin() + m, target);
                } else {
                    l = m + 1; // continue search
                }
            } else if (nums[m] < pivot) {
                if (nums[m] == target) {
                    return true;
                } else if (nums[m] < target && nums[r] > target) {
                    return binary_search(nums.begin() + m, nums.end(), target);
                } else {
                    r = m - 1;
                }
            } else {
                l = l + 1;
            }
        }
        return false;
    }
};
