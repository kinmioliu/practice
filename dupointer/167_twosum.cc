class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int inx1 = 0;
        int inx2 = numbers.size() - 1;
        while (numbers[inx1] + numbers[inx2] < target) {
            inx1++;
        }
        for (int i = inx1; i < numbers.size() - 1; i++) {
            if (binary_search(numbers.begin() + i + 1, numbers.end(), target - numbers[i])) {                
                auto low = lower_bound(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);
                int inx = low - numbers.begin() + 1;
                return vector<int>{i + 1, inx};
            }
        }
        return vector<int>();
    }
    vector<int> twoSumOpti(vector<int>& numbers, int target) {
        int inx1 = 0;
        int inx2 = numbers.size() - 1;
        while (numbers[inx1] + numbers[inx2] != target) {
            if (numbers[inx1] + numbers[inx2] > target) {
                inx2--;
            } else {
                inx1++;
            }
        }
        return vector<int>{inx1, inx2};
    }
};

