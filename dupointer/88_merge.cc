class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int inx1 = m - 1;
        int inx2 = n - 1;
        int inx3 = m + n - 1;
        while (inx1 >= 0 && inx2 >= 0) {
            if (nums1[inx1] > nums2[inx2]) {
                nums1[inx3--] = nums1[inx1--];
            } else { // less or eq
                nums1[inx3--] = nums2[inx2--];
            }
        }
        while (inx1 >= 0) {
            nums1[inx3--] = nums1[inx1--];
        }
        while (inx2 >= 0) {
            nums1[inx3--] = nums2[inx2--];
        }
    }
};
