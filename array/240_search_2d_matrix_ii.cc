class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1, convex;
        for (; i < m && j >= 0;) {
            convex = matrix[i][j];
            if (target < convex) {
                if (target < matrix[i][0]) {
                    return false;
                }
                j--;
                continue;
            } else if (target > convex) {
                if (target > matrix[j][n - 1]) {
                    return false;
                }
                i++;
                continue;
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1, convex;
        for (; i < m && j >= 0;) {
            convex = matrix[i][j];
            if (target < convex) {
                if (target < matrix[i][0]) {
                    return false;
                }
                j--;
                continue;
            } else if (target > convex) {
                if (target > matrix[m - 1][j]) {
                    return false;
                }
                i++;
                continue;
            } else {
                return true;
            }
        }
        return false;
    }
};

