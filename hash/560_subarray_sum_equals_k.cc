class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSums(nums.size());
        prefixSums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSums[i] = nums[i] + prefixSums[i - 1];
        }
        int rangeSum;
        int sumkCnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i; j < nums.size(); j++) {
                if (i == 0) {
                    rangeSum = prefixSums[j];
                } else {
                    rangeSum = prefixSums[j] - prefixSums[i - 1];
                }
                if (rangeSum == k) {
                    sumkCnt++;
                }
            }
        }
        return sumkCnt;
    }
};

class Solution {
public:
    int subarraySumTimeLimit(vector<int>& nums, int k) {
        vector<int> prefixSums(nums.size());
        prefixSums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSums[i] = nums[i] + prefixSums[i - 1];
        }
        int rangeSum;
        int sumkCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (i == 0) {
                    rangeSum = prefixSums[j];
                } else {
                    rangeSum = prefixSums[j] - prefixSums[i - 1];
                }
                if (rangeSum == k) {
                    sumkCnt++;
                }
            }
        }
        return sumkCnt;
    }
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSums(nums.size());
        unordered_map<int, vector<int>> hash;
        int sumCnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                sumCnt++; // range[0, i]
            }
            sumCnt += hash[sum - k].size(); // range[pre, i] pre < i
            hash[sum].push_back(i);
        }
        return sumCnt;
    }

};

